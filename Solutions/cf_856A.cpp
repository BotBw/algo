#include "bits/stdc++.h"

void solve() {
  int n;
  cin >> n;
  vector<string> a;
  FOR(i, 1, 2 * n - 2) {
    string s;
    cin >> s;
    if(s.size() == n - 1) {
      a.push_back(s);
    }
  }
  reverse(a[0].begin(), a[0].end());
  if(a[0] == a[1]) cout << "YES\n";
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