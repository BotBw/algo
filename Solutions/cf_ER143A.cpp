#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n, m;
    cin >> n >> m;
    vector<char> l(n), r(m);
    FOR(i, 0, n-1) cin >> l[i];
    FOR(i, 0, m-1) cin >> r[i];
    reverse(r.begin(), r.end());
    FOR(i, 0, m-1) l.push_back(r[i]);
    int cnt = 0;
    FOR(i, 1, n + m - 1) {
      if(l[i] == l[i-1]) cnt++;
    }
    cout << (cnt <= 1 ? "YES" : "NO") << endl;
  }
  return 0;
}