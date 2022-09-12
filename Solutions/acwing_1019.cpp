#include "bits/stdc++.h"

struct item {
  int v, w, s;
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<item> a(n + 1);
  FOR(i, 1, n) cin >> a[i].v >> a[i].w >> a[i].s;
  vector<ll> f(m + 1);
  FOR(i, 1, n) {
    FOR(j, 1, a[i].s) {
      _FOR(k, m, a[i].v) {
        f[k] = max(f[k], f[k - a[i].v] + a[i].w);
      }
    }
  }
  cout << f[m] << endl;
  return 0;
}