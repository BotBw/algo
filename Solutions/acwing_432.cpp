#include "bits/stdc++.h"

const int T = 1005, M = 105;

int cost[M], val[M];
int f[T];
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t, m;
  cin >> t >> m;
  FOR(i, 1, m) cin >> cost[i] >> val[i];
  FOR(i, 1, m) {
    _FOR(j, t, cost[i]) {
      f[j] = max(f[j], f[j - cost[i]] + val[i]);
    }
  }
  cout << f[t];
  return 0;
}