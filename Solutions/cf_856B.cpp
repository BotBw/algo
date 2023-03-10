#include "bits/stdc++.h"

void solve() {
  int n;
  cin >> n;
  
  vector<int> a(n + 1);

  FOR(i, 1, n) {
    cin >> a[i];
  }

  /*
    1 n -> 2 n ?> 3 n
    2 -> 12
  */
  FOR(i, 1, n) if(a[i] == 1) a[i]++;

  FOR(i, 2, n) {
    if(a[i] % a[i-1] == 0) a[i]++;
  }
  
  FOR(i, 1, n) cout << a[i] << " \n"[i == n];
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