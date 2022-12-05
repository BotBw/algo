#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  vector<vector<int>> f(n+1, vector<int>(3, -INT_INF));
  int ans = 0;
  f[0][0] = 0;
  FOR(i, 1, n) {
    if(i - 2 >= 0) {
      f[i][0] = max(f[i-1][2], f[i-1][0]);
    } else {
      f[i][0] = f[i-1][0];
    }
    f[i][1] = max(f[i-1][0] - a[i], f[i-1][1]);
    f[i][2] = f[i-1][1] + a[i];
    ans = max({ans, f[i][0], f[i][2]});
  }
  cout << ans;
  return 0;
}