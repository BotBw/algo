#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> st;
  FOR(i, 0, (1 << n) - 1) {
    if ((i << 1 & i) == 0 && (i >> 1 & i) == 0 && __builtin_popcount(i) <= k)
      st.push_back(i);
  }
  vector<vector<vector<ll>>> f(n + 1, vector<vector<ll>>(st.size(), vector<ll>(k + 1)));
  f[0][0][0] = 1;
  FOR(i, 1, n) {
    FOR(j, 0, (int)st.size() - 1) {
      FOR(kk, 0, (int)st.size() - 1) {
        int cnt = __builtin_popcount(st[kk]);
        FOR(p, cnt, k) {
          if((st[kk] << 1 & st[j]) == 0 && (st[kk] >> 1 & st[j]) == 0 && (st[kk] & st[j]) == 0)
            f[i][kk][p] += f[i-1][j][p-cnt];
        }
      }
    }
  }
  ll res = 0;
  FOR(j, 0, (int)st.size() - 1) res += f[n][j][k];
  cout << res;
  return 0;
}