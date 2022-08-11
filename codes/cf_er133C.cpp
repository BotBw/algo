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
  FOR(_, 1, tt) {
    int m;
    cin >> m;
    vector<vector<int>> a(2, vector<int>(m + 1));
    FOR(i, 0, 1)
      FOR(j, 1, m) cin >> a[i][j];
    
    a[0][1] = -1;

    vector<vector<int>> dp(2, vector<int>(m + 2));

    _FOR(j, m, 1) {
      FOR(i, 0, 1) {
        dp[i][j] = max({a[i][j] + 1 + 2*(m - j) + 1, a[i^1][j] + 1, dp[i][j+1] + 1});
      }
    }

    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, 1};
    int dir = 0;

    int i = 0, j = 1;
    int cur = 0;
    int res = INT_INF;
    debug(dp[0]);
    debug(dp[1]);
    while(true) {
      if(dir == 0 || dir == 2) {
        if(cur + 2 * (m - j) + 1 >= dp[i][j]) res = min(res, cur + 2 * (m - j) + 1);
        else res = min(res, dp[i][j]);
      }
      if(res == 16) debug(i, j, cur);

      i += dx[dir];
      j += dy[dir];
      if(j > m) {
        res = min(res, cur);
        break;
      }
      cur = max(cur + 1, a[i][j] + 1);
      dir = (dir + 1) % 4;
    }
    cout << res << endl;
  }
  return 0;
}