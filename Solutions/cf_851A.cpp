#include "bits/stdc++.h"

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);

  FOR(i, 1, n) cin >> a[i];

  int cnt1 = 0;

  FOR(i, 1, n) if(a[i] == 2) cnt1++;

  int cnt2 = 0;

  int k = -1;
  FOR(i, 1, n) {
    if(a[i] == 2) cnt2++;
    if(cnt2 * 2 == cnt1) {
      k = i;
      break;
    }
  }

  cout << k << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}