#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  FOR(_, 1, t) {
    int n;
    cin >> n;
    if(n % 2) {
      FOR(i, 1, n) cout << 1 << ' ';
    } else {
      cout << 1 << ' ' << 3 << ' ';
      FOR(i, 3, n) cout << 2 << ' ';
    }
    cout << endl;
  }
  return 0;
}