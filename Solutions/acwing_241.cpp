#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxn = 2e5 + 5;
// const int maxn = 10;

struct seg_tree {

  ll t[maxn*4];

  seg_tree() {
    memset(t, 0, sizeof t);
  }

  void update(int i, int tl, int tr, int l, int r, int x) {
    if(l <= tl && tr <= r) {
      t[i] += x;
      return;
    }
    int mi = (tl + tr)/2;
    if(l <= mi) update(i*2, tl, mi, l, r, x);
    if(mi < r) update(i*2+1, mi+1, tr, l, r, x);
    t[i] = t[i*2] + t[i*2+1];
  }

  ll query(int i, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l <= tl && tr <= r) {
      return t[i];
    }
    int mi = (tl+tr)/2;
    ll ans = 0;
    if(l <= mi) ans += query(i*2, tl, mi, l, r);
    if(mi < r) ans += query(i*2+1, mi+1, tr, l, r);
    return ans;
  }
};

int n, arr[maxn];
ll lless[maxn], ggreater[maxn];

#ifdef LEET
#include "leet.h"
#else
int main() {
  ll ans1 = 0, ans2 = 0;
  cin >> n;
  FOR(i, 1, n) {
    cin >> arr[i];
  }
  seg_tree s, s_r;
  FOR(i, 1, n) {
    lless[i] = s.query(1, 1, n, 1, arr[i]-1);
    ggreater[i] = s.query(1, 1, n, arr[i]+1, n);
    s.update(1, 1, n, arr[i], arr[i], 1);
  }
  _FOR(i, n, 1) {
    ans1 += ggreater[i] * s_r.query(1, 1, n, arr[i] + 1, n);
    ans2 += lless[i] * s_r.query(1, 1, n, 1, arr[i]-1);
    s_r.update(1, 1, n, arr[i], arr[i], 1);
  }
  cout << ans1 << ' ' << ans2;
  return 0;
}
#endif