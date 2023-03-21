#include "bits/stdc++.h"

void solve() {
  string a, b;
  cin >> a >> b;
  if(a[0] == b[0]) {
    cout << "YES\n";
    cout << a[0] << "*\n";
    return;
  }
  if(a.back() == b.back()) {
    cout << "YES\n";
    cout << "*" << a.back() << '\n';
    return;
  }

  FOR(i, 0, a.size() - 2) {
    char c1 = a[i], c2 = a[i + 1];
    FOR(j, 0, b.size() - 2) {
      if(b[j] == c1 && b[j + 1] == c2) {
        cout << "YES\n";
        cout << "*" << c1 << c2 << "*\n";
        return;
      }
    }
  }
  cout << "NO\n";
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