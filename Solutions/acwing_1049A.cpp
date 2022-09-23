#include "bits/stdc++.h"

const int N = 1e5 + 10;
int n, a[N], f[N][2];

signed main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    FOR(i ,1 ,n) cin >> a[i];
    FOR(i, 1, n) {
      f[i][0] = max(f[i-1][0], f[i-1][1]);
      f[i][1] = f[i-1][0] + a[i];
    }
    cout << max(f[n][0], f[n][1]) << endl;
  }
  return 0;
}