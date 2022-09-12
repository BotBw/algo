#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  vector<ll> f(m + 1);
  f[0] = 1;
  FOR(i, 1, n) {
    FOR(j, a[i], m) {
      f[j] += f[j - a[i]];
    }
  }
  cout << f[m] << endl;
  return 0;
}