#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4+5, maxV = maxN;

int weight[maxN], value[maxN], number[maxN];

int f[maxV];

int N, V;

// Zero-One Knapsack for one item
void zeroOneKnapsack(int weight, int value) {
  for(int j = V; j >= weight; j--)
    f[j] = max(f[j], f[j-weight]+value);
}

// Complete Knapsack for one item
void completeKnapsack(int weight, int value) {
  for(int j = weight; j <= V; j++) {
    f[j] = max(f[j], f[j-weight]+value);
  }
}

// Multiple Knapsack for one item
// a. binary optimization
void binaryKnapsack(int weight, int value, int number) {
  if(weight*number >= V) {
    completeKnapsack(weight, value);
    return;
  }
  int k = 1;
  while(k < number) {
    zeroOneKnapsack(k*weight, k*value);
    number -= k;
    k *= 2;
  }
  zeroOneKnapsack(number*weight, number*value);
}
// b. mono-queue optimization
void monoQueueKnapsack(int weight, int value, int number) {
  if(weight*number >= V) {
    completeKnapsack(weight, value);
    return;
  }
  int q1[maxN], q2[maxN];
  int head, tail;
  for(int d = 0; d < weight; d++) {
    head = 1, tail = 0;
    for(int k1 = 0; k1 <= (V-d)/weight; k1++) {
      int j = k1*weight+d;
      while(head <= tail && f[j]-k1*value >= q2[tail]) tail--;
      q1[++tail] = k1;
      q2[tail] = f[j]-k1*value;
      while(head <= tail && k1-q1[head] > number) head++;
      f[j] = max(f[j], q2[head]+k1*value);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> N >> V;
  for(int i = 1; i <= N; i++) cin >> weight[i] >> value[i] >> number[i];
/*
  for(int i = 1; i <= N; i++) {
    switch(number[i]) {
      case 0:
        completeKnapsack(weight[i], value[i]);
        break;
      case 1:
        zeroOneKnapsack(weight[i], value[i]);
        break;
      default:
        monoQueueKnapsack(weight[i], value[i], number[i]);
    }
  }
*/
  cout << f[V];
  return 0;
}