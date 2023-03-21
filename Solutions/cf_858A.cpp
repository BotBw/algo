#include "bits/stdc++.h"

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int dx = c - a, dy = d - b;
  if((dy >= 0 && dy >= dx)) {
    cout << dy + (a + dy - c) << endl;
  } else cout << -1 << endl;
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