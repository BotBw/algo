#include "bits/stdc++.h"

void solve() {
  int n, k;
  cin >> n >> k;
  bool lk = false, rk = false;
  FOR(i, 0, n-1) {
    int l, r;
    cin >> l >> r;
    if(l == k) lk = true;
    if(r == k) rk = true;
  }
  if(lk && rk) cout << "YES\n";
  else cout << "NO\n";
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