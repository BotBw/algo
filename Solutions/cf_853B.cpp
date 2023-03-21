#include "bits/stdc++.h"

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, r = n - 1;
  while(l <= r && s[l] == s[r]) l++, r--;
  while(l <= r && s[l] != s[r]) l++, r--;
  while(l <= r) {
    if(s[l] != s[r]) {
      cout << "No\n";
      return;
    }
    l++, r--;
  }
  cout << "Yes\n";
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