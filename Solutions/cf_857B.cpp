#include "bits/stdc++.h"

void solve() {
  int n;
  cin >> n;

  int cnt = 0;
  int avail = 0;
  int box = 0;
  
  FOR(i, 1, n) {
    int bi;
    cin >> bi;
    if(bi == 1) {
      cnt++;
      avail--;
      if(avail < 0) {
        avail++;
        box++;
      }
    } else {
      avail = box - (1 + cnt / 2);
    }
    // debug(i, bi, box, avail);
  }
  cout << box << '\n';
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