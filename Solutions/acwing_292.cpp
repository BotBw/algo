#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int m, n;
  cin >> m >> n;
  vector<int> no(m + 1);
  FOR(i, 1, m) {
    int st = 0;
    FOR(j, 0, n-1) {
      char c;
      cin >> c;
      int k = c == 'H' ? 1 : 0;
      st |= k << j;
    }
    no[i] = st;
  }
  vector<int> st;
  FOR(i, 0, (1 << n) - 1) {
    if ((i << 1 & i) == 0 && (i >> 1 & i) == 0
        && (i << 2 & 1) == 0 && (i >> 2 & i) == 0)
      st.push_back(i);
  }
  vector<vector<vector<ll>>> f(m + 1, vector<vector<ll>>(st.size(), vector<ll>(st.size())));

  f[0][0][0] = 0;
  int sz = st.size();
  FOR(i, 1, m) {
    FOR(j, 0, sz-1) {
      if(st[j] & no[i]) continue;
      int cnt = __builtin_popcount(st[j]);
      FOR(jj, 0, sz-1) {
        FOR(jjj, 0, sz-1) {
          if((st[j] & st[jj]) || (st[j] & st[jjj])) continue;
          f[i][j][jj] = max({f[i][j][jj], f[i-1][jj][jjj] + cnt});
        }
      }
    }
  }

  ll res = 0;
  FOR(j, 0, sz-1) {
    FOR(jj, 0, sz-1) {
      res = max({res, f[m][j][jj]});
    }
  }
  cout << res;
  return 0;
}