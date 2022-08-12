#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)


const int maxn = 1e5 + 5;
// const int maxn = 10;
int n, arr[maxn];

int t[maxn*4];

void build(int i = 1, int l = 1, int r = n) {
  if(l==r) {
    t[i] = 1;
    return;
  }
  int mi = (l+r)/2;
  build(i*2, l, mi);
  build(i*2+1, mi+1, r);
  t[i] = t[i*2] + t[i*2 + 1];
}

int query(int l, int r, int tl = 1, int tr = n, int i = 1) {
  if(l <= tl && tr <= r) {
    return t[i];
  }
  int mi = (tl + tr)/2, ans = 0;
  if(l <= mi) ans += query(l, r, tl, mi, i*2);
  if(mi < r) ans += query(l, r, mi+1, tr, i*2+1);
  return ans;
}

void update(int l, int r, int inc, int tl = 1, int tr = n, int i = 1) {
  if(l <= tl && tr <= r) {
    t[i] += inc;
    return;
  }
  int mi = (tl + tr)/2;
  if(l <= mi) update(l, r, inc, tl, mi, i*2);
  if(mi < r) update(l, r, inc, mi+1, tr, i*2+1);
  t[i] = t[i*2] + t[i*2+1];
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n;
  FOR(i, 2, n) cin >> arr[i]; // O(n)
  build();
  _FOR(i, n, 1) { 
    int l = 1, r = n;
    int k = arr[i] + 1;
    while(l < r) {
      int mi = (l + r)/2;
      int ans = query(1, mi);
      if(ans >= k) {
        r = mi;
      } else {
        l = mi + 1;
      }
    }
    arr[i] = r;
    update(r, r, -1);
  }
  FOR(i, 1, n) {
    cout << arr[i] << endl;
  }
  return 0;
}
#endif