#include "bits/stdc++.h"

const int N = 1005, M = 505, K = 105;


struct info {
  int ball, damage;
} a[K];

int f[N][M];
int da[N][M];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  FOR(i, 1, k) cin >> a[i].ball >> a[i].damage;
  FOR(i, 1, k) {
    _FOR(j, n, a[i].ball) {
      _FOR(x, m, a[i].damage + 1) {
        if(f[j - a[i].ball][x - a[i].damage] + 1 > f[j][x]) {
          f[j][x] = f[j - a[i].ball][x - a[i].damage] + 1;
          da[j][x] = da[j - a[i].ball][x - a[i].damage] + a[i].damage;
        } else if (f[j - a[i].ball][x - a[i].damage] + 1 == f[j][x]) {
            da[j][x] = min(da[j][x], da[j - a[i].ball][x - a[i].damage] + a[i].damage);
        }
      }
    }
  }
  cout << f[n][m] << " " << m - da[n][m];
  return 0;
}