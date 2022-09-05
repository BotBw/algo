#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(_, 1, tt) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    int id = -1;
    FOR(i, 1, n) {
      cin >> a[i];
      if(a[i] == n) id = i;
    }
    deque<int> qe;
    vector<vector<int>> win(n + 1);
    FOR(i, 1, n) qe.push_back(i);
    FOR(i, 1, id-1) {
      int ftr = qe[0];
      qe.pop_front();
      int sec = qe[0];
      qe.pop_front();
      if(a[ftr] > a[sec]) {
        win[ftr].push_back(i);
        qe.push_front(ftr);
        qe.push_back(sec);
      } else {
        win[sec].push_back(i);
        qe.push_back(ftr);
        qe.push_front(sec);
      }
    }
    debug(win);
    FOR(j, 1, q) {
      int i, k;
      cin >> i >> k;
      int res = upper_bound(win[i].begin(), win[i].end(), k) - win[i].begin();
      debug(res);
      if(i == id) {
        res += max(0, k - id + 1);
      }
      cout << res << endl;
    }
  }
  return 0;
}