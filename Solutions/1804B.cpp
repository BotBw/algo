#include "bits/stdc++.h"

void solve() {
  int n, k, d, w;
  cin >> n >> k >> d >> w;
  vector<int> t(n + 1);
  FOR(i, 1, n) cin >> t[i];
  int ans = 0;
  
  for(int l = 1; l <= n; ) {
    int r = l;
    while(r <= n && r - l + 1 <= k && t[r] - t[l] <= d + w) {
      r++;
    }
    r--;
    l = r + 1;
    ans++;
  }
  cout << ans << endl;
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