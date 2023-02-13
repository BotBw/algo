#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int x, y;
    cin >> x >> y;
    int n = 2 * (x - y);
    vector<int> a(n);
    int i = 0;
    FOR(c, y, x) a[i++] = c;
    _FOR(c, x-1, y + 1) a[i++] = c;
    cout << n << endl;
    for(auto v:a) cout << v << " ";
    cout << endl;
  }
  return 0;
}