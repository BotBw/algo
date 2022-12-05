#include "bits/stdc++.h"

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int m = s.size();
  vector<int> f(m);
  FOR(i, 1, m-1) {
    int j = f[i-1];
    while(j && s[i] != s[j]) j = f[j-1];
    if(s[i] == s[j]) f[i] = j + 1;
  }
  modint::setmod(1e9 + 7);
  vector<vector<modint>> dp(n + 1, vector<modint>(m, 0));
  dp[0][0] = 1;
  FOR(i, 1, n) {
    FOR(j, 0, 25) {
      char c = 'a' + j;
      FOR(k, 0, m-1) {
        int kk = k;
        while(kk && s[kk] != c) {
          kk = f[kk-1];
        }
        if(s[kk] == c) kk++;
        if(kk != m) {
          dp[i][kk] += dp[i-1][k];
        }
      }
    }
  }
  modint ans = 0;
  FOR(k, 0, m-1) ans += dp[n][k];
  cout << ans;
  return 0;
}