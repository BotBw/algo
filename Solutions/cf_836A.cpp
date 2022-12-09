#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(_, 1, T) {
    string a;
    cin >> a;
    cout << a;
    reverse(a.begin(), a.end());
    cout << a;
    cout << endl;
  }
  return 0;
}