#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int m, n;
  cin >> m >> n;
  vector<int> no(m + 1);
  FOR(i, 1, m) {
    int st = 0;
    FOR(j, 0, n-1) {
      int k;
      cin >> k;
      k ^= 1;
      st |= k << j;
    }
    no[i] = st;
  }
  vector<int> st;
  FOR(i, 0, (1 << n) - 1) {
    if ((i << 1 & i) == 0 && (i >> 1 & i) == 0)
      st.push_back(i);
  }
  vector<vector<ll>> f(m + 1, vector<ll>(st.size()));
  f[0][0] = 1;
  FOR(i, 1, m) {
    FOR(j, 0, (int)st.size() - 1) {
     if((st[j] & no[i]) != 0) continue;
     FOR(k, 0, (int)st.size() - 1) {
      if((st[j] & st[k]) != 0) continue;
      f[i][j] += f[i-1][k];
     }
    }
  }
  ll res = 0;
  FOR(j, 0, (int)st.size() - 1) res += f[m][j];
  cout << (res % (ll)1e8);
  return 0;
}