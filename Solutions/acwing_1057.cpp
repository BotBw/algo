#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  vector<vector<vector<int>>> f(2, vector<vector<int>>(k + 1, vector<int>(2, -INT_INF)));
  int ans = 0;
  f[0][0][0] = 0;
  FOR(i, 1, n) {
    FOR(j, 0, k) {
      if (j > 0)
        f[i & 1][j][0] = max(f[i-1 & 1][j-1][1] + a[i], f[i-1 & 1][j][0]);
      else
        f[i & 1][j][0] = f[i-1 & 1][j][0];
      f[i & 1][j][1] = max(f[i-1 & 1][j][0] - a[i], f[i-1 & 1][j][1]);
      ans = max(ans, f[i & 1][j][0]);
    }
  }
  cout << ans;
  return 0;
}

/*
f[i, j, k]

f[i, j, 0] = max(f[i-1, j-1, 1] + a[i], f[i-1, j, 0])
f[i, j, 1] = max(f[i-1, j, 0] - a[i], f[i-1, j, 1])


*/