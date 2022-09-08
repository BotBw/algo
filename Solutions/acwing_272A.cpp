#include "bits/stdc++.h"

const int N = 3005;
int f[N][N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  // f[i, j] 考虑前i个a[i]， 以b[j]结尾
  //  if a[i] == b[j]
  //      if b[j] > b[k] f[i, j] = max({f[i-1, k] + 1})
  //      if b[j] <= b[k] f[i, j] = 1
  //  if a[i] != b[j]
  //      f[i, j] = max{f[i-1, j]}
  int pre = 0, res = 0;
  FOR(i, 1, n) {
    pre = 0;
    FOR(j, 1, n) {
      if(a[i] == b[j]) {
        f[i][j] = max(1, pre + 1);
      } else {
        f[i][j] = f[i-1][j];
      }
      if(a[i] > b[j]) pre = max(pre, f[i][j]);
    }
  }
  FOR(j, 1, n) res = max(res, f[n][j]);
  cout << res;
  return 0;
}