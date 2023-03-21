#include "bits/stdc++.h"

string s;

void solve() {
  int n = s.size();
  int k;
  string c;
  cin >> k >> c;
  bool ok = false;
  FOR(i, 0, n - k) {
    if(c == s.substr(i, k))  {
      ok = true;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  FOR(i, 1, 100) {
    if(i % 3 == 0) s.push_back('F');
    if(i % 5 == 0) s.push_back('B');
  }
  int t;
  cin >> t;
  FOR(i ,1, t) solve();
  return 0;
}