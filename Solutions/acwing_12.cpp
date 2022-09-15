#include "bits/stdc++.h"


const int N = 1005, V = N;
int pre[N][V];
int f[V];
int n, vv;
int w[N], v[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> vv;
  FOR(i, 1, n) cin >> v[i] >> w[i];
  _FOR(i, n, 1) {
    _FOR(j, vv, v[i]) {
      if(f[j] <= f[j - v[i]] + w[i]) {
        f[j] = f[j - v[i]] + w[i];
        pre[i][j] = v[i];
      }
    }
  }
  vector<int> res;
  int j = vv;
  FOR(i, 1, n) {
    if(pre[i][j]) res.push_back(i);
    j -= pre[i][j];
  }
  FOR(i, 0, res.size() - 1) cout << res[i] << ' ';
  return 0;
}