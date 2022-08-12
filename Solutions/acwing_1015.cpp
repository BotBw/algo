#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t ,1, tt) {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> g(r + 1, vector<int>(c + 1)), dp(r + 1, vector<int>(c + 1, -INT_INF));
    FOR(i, 1, r) 
      FOR(j, 1, c) cin >> g[i][j];
    dp[0][1] = dp[1][0] = 0;
    FOR(i, 1, r)
      FOR(j, 1, c)
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + g[i][j];
    cout << dp[r][c] << endl;
  }
  return 0;
}