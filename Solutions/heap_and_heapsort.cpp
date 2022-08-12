#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

const int maxn = 1e3;

int heap[maxn], sz;

bool cmp(int a, int b) { // true: a should be the father of b
  return a > b;
}

void percolateUp(int id) {
  int i = id;
  while(i > 1 && cmp(heap[i], heap[i/2])) {
    swap(heap[i], heap[i/2]);
    i /= 2;
  }
}

void percolateDown(int id) {
  int i = id;
  while(i*2 <= sz) {
    int lc = i*2;
    if(lc + 1 <= sz && cmp(heap[lc+1], heap[lc])) lc++;
    if(cmp(heap[i], heap[lc])) break;
    swap(heap[i], heap[lc]);
    i = lc;
  }
}

void insert(int val) {
  heap[++sz] = val;
  percolateUp(sz);
}

void remove() {
  swap(heap[1], heap[sz--]);
  percolateDown(1);
}

void heapify(int n) {
  sz = n;
  for(int i = sz/2; i >= 1; i--) percolateDown(i);
}

int n;
int arr[maxn];
int main() {
  while(cin >> heap[++n]) {} 
  n--;
  heapify(n);

  _FOR(i, n, 1) {
    swap(heap[1], heap[i]);
    sz--;
    percolateDown(1);
  }
  FOR(i, 1, n) cout << heap[i] << ' ';
  // cout << endl;
  // FOR(i, 1, n) cout << arr[i] << ' ';
  return 0;
}