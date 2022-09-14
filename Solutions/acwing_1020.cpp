#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int m, n;
  // f[i, j, k] = min(f[i-1, j, k], {f[i - 1, j - oxygen[i], k - nitrogen[i]] + w[i]});
  cin >> m >> n;
  vector<vector<int>> f(m + 1, vector<int>(n + 1, INT_INF));
  int k;
  cin >> k;
  vector<int> nitrogen(k + 1), oxygen(k + 1), w(k + 1);
  FOR(i, 1, k) cin >> oxygen[i] >> nitrogen[i] >> w[i];
  f[0][0] = 0;
  FOR(i, 1, k) {
    _FOR(j, m, 0) {
      _FOR(p, n, 0) {
        f[j][p] = min(f[j][p], f[max(0, j - oxygen[i])][max(0, p - nitrogen[i])] + w[i]);
      }
    }
  }
  debug(f);
  cout << f[m][n];
  return 0;
}