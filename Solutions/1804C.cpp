#include "bits/stdc++.h"


void solve() {
  int n, x, p;
  cin >> n >> x >> p;
  FOR(f, 1, min(2 * n, p)) {
    if((x + 1LL * f * (f + 1) / 2) % n == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}