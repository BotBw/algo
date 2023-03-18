#include "bits/stdc++.h"

void solve() {
  int a, b;
  cin >> a >> b;
  int diffRow = abs(a), diffCol = abs(b);
  int diffRowAndCol = abs(diffRow - diffCol);
  int interleave = min(diffRow, diffCol);
  cout << interleave * 2 + max(0, 2*diffRowAndCol - 1) << endl;
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