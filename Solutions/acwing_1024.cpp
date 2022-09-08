#include "bits/stdc++.h"
const int V = 20005, N = 31;

int volume[N];
int f[V];
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int v, n;
  cin >> v >> n;
  FOR(i, 1, n) cin >> volume[i];
  FOR(i, 1, n) {
    _FOR(j, v, volume[i]) {
      f[j] = max(f[j], f[j - volume[i]] + volume[i]);
    }
  }
  cout << v - f[v];
  return 0;
}