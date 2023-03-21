#include "bits/stdc++.h"

void solve() {
  int n;
  cin >> n;
  map<int, int> cnt;
  FOR(i, 1, n) {
    int ai;
    cin >> ai;
    cnt[ai]++;
  }

  int cnt0 = cnt[0], cntOthers = n - cnt0;
  if(cnt0 == 0) cout << 0 << endl;
  else if(cnt0 <= cntOthers + 1) cout << 0 << endl;
  else if(cnt[1] == 0 || cnt.lower_bound(2) != cnt.end()) cout << 1 << endl;
  else cout << 2 << endl; 
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