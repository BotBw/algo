#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &v:a) cin >> v;
    int l = 0, r = n-1;
    int mn = 1, mx = n;
    while(r - l + 1 > 3) {
      if(a[l] == mn) {
        l++;
        mn++;
      } else if(a[r] == mn) {
        r--;
        mn++;
      } else if(a[l] == mx) {
        l++;
        mx--;
      } else if(a[r] == mx) {
        r--;
        mx--;
      } else {
        break;
      }
    }
    if(r - l + 1 > 3){
      cout << l + 1 << " " << r + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}