#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(2*n + 1), pre(2*n + 1);
  FOR(i, 1, n) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  n = n * 2 - 1;
  FOR(i, 1, n) {
    pre[i] = pre[i - 1] + a[i];
  }
  vector<vector<int>> f1(n + 1, vector<int>(n + 1)), f2(n + 1, vector<int>(n + 1));
  FOR(l, 2, n) {
    FOR(i, 1, n - l + 1) {
      int j = i + l - 1;
      int maxf = 0;
      FOR(k, i + 1, j) {
        maxf = max({maxf, f1[i][k-1] + f1[k][j] + pre[j] - pre[i-1]});
      }
      f1[i][j] = maxf;
    }
  }
  FOR(l, 2, n) {
    FOR(i, 1, n - l + 1) {
      int j = i + l - 1;
      int minf = INT_INF;
      FOR(k, i + 1, j) {
        minf = min({minf, f2[i][k-1] + f2[k][j] + pre[j] - pre[i-1]});
      }
      f2[i][j] = minf;
    }
  }
  n = (n + 1)/2;
  int ans1 = INT_INF, ans2 = 0;
  FOR(i, 1, n) {
    ans1 = min({ans1, f2[i][i + n - 1]});
    ans2 = max({ans2, f1[i][i + n - 1]});
  }
  cout << ans1 << endl << ans2 << endl;
  return 0;
}