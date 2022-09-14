#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, m;
  cin >> N >> m;
  vector<int> f(N + 1);
  FOR(i, 1, m) {
    int v, p;
    cin >> v >> p;
    int val = v * p;
    _FOR(j, N, v) {
      f[j] = max(f[j], f[j - v] + val);
    }
  }
  cout << f[N];
  return 0;
}