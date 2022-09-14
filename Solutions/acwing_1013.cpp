#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n + 1, vector<int>(m + 1));
  FOR(i, 1, n) 
    FOR(j, 1, m) 
      cin >> mat[i][j];
  
  vector<int> f(m + 1), ans(n + 1);
  vector<vector<int>> pre(n + 1, vector<int>(m + 1));
  FOR(i, 1, n) {
    _FOR(j, m, 1) {
      FOR(k, 0, j) {
        if(f[j - k] + mat[i][k] > f[j]) {
          f[j] = f[j - k] + mat[i][k];
          pre[i][j] = k;
        }
      }
    }
  }
  int cur = m;
  _FOR(i, n, 1) {
    ans[i] = pre[i][cur];
    cur -= ans[i];
  }
  cout << f[m] << endl;
  FOR(i, 1, n) cout << i << ' ' << ans[i] << endl;
  return 0;
}