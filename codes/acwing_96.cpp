#include <bits/stdc++.h>
using namespace std;

const int N = 13;
int f1[N], f2[N];

int work1(int n) {
  if(f1[n] != -1) return f1[n];
  if(n == 0) return f1[n] = 0;
  int a = work1(n-1);
  return f1[n] = a * 2 + 1;
}

int work2(int n) {
  if(f2[n] != -1) return f2[n];
  if(n == 0) return f2[n] = 0;
  int sum = n - 1;
  int mins = 0x3f3f3f3f;
  for(int i = 0; i <= sum; i++) {
    mins = min(mins, 2*work2(i) + 2*work1(sum - i) + 1);
  }
  return f2[n] = mins; 
}


int main() {
  memset(f1, -1, sizeof f1);
  memset(f2, -1, sizeof f2);
  for(int i = 1; i <= 12; i++) {
    cout << work2(i) << endl;
  }
  return 0;
}