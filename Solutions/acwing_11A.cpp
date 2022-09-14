#include "bits/stdc++.h"

const int N = 1005, V = N;

modint cnt[V];
int f[V];
int w[N], v[N];

int vv, n;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> vv;
  FOR(i, 1, n) cin >> v[i] >> w[i];
  modint::setmod(1e9 + 7);
  FOR(i, 0, vv) cnt[i] = 1;
  FOR(i, 1, n) {
    _FOR(j, vv, v[i]) {
      if(f[j] < f[j - v[i]] + w[i]) {
        f[j] = f[j - v[i]] + w[i];
        cnt[j] = cnt[j - v[i]];
      } else if(f[j] == f[j - v[i]] + w[i]) {
        cnt[j] += cnt[j - v[i]];
      }
    }
  }
  cout << cnt[vv];
  return 0;
}