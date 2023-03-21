#include "bits/stdc++.h"

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  bool one = false;
  vector<int> a(n + 1);
  FOR(i, 1, n) {
    cin >> a[i];
  }
  if(one == true) {
    cout << "Yes\n";
    return;
  }
  FOR(i, 1, n) {
    FOR(j, 1, i - 1) {
      if(gcd(a[i], a[j]) == 1 || gcd(a[i], a[j]) == 2) {
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
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