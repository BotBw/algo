#include "bits/stdc++.h"

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &v: a) cin >> v;
  int l = 0, r = n - 1;
  int mn = 1, mx = n;

  while(l <= r) {
    if(a[l] == mn) {
      l++;
      mn++;
    } else if(a[l] == mx) {
      l++;
      mx--;
    } else if(a[r] == mn) {
      r--;
      mn++;
    } else if(a[r] == mx) {
      r--;
      mx--;
    } else {
      break;
    }
  }
  l++;
  r++;
  if(l <= r) {
    cout << l << " " << r << endl;
  } else cout << -1 << endl;
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