#include "bits/stdc++.h"

void solve() {
  int n;
  cin >> n;

  vector<bool> up(n + 1), down(n + 1);

  FOR(i, 1, n) {
    int ai;
    cin >> ai;
    if(ai > 0) up[ai] = true;
    if(ai < 0) down[-ai] = true;
  }

  int cntBoth = 0, cntUp = 0;

  FOR(i, 1, n) {
    if(up[i] && down[i]) cntBoth++;
    if(up[i]) cntUp++;
  }

  debug(cntUp, cntBoth);

  FOR(i, 1, n) {
    if(i <= cntUp) cout << i;
    else cout << cntUp - (i - cntUp);
    cout << " \n"[i == n];
  }

  FOR(i, 1, n) {
    if(i / 2 <= cntBoth) cout << i % 2;
    else cout << i - cntBoth * 2;
    cout << " \n"[i == n];
  }

  
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