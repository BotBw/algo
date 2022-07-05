#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
typedef long long LL;
typedef pair<LL, LL> PLL;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  unordered_map<char, int> m;
  m['N'] = 0;
  m['E'] = 1;
  m['S'] = 2;
  m['W'] = 3;
  FOR(t, 1, T) {
    int n, r, c, sr, sc;
    cin >> n >> r >> c >> sr >> sc;
    string op;
    cin >> op;
    vector<vector<bool>> vis(r + 1, vector<bool>(c + 1));
    vis[sr][sc] = 1;
    int x = sr, y = sc;
    FOR(i, 0, n-1) {
      int dir = m[op[i]];
      int xx = x + dx[dir], yy = y + dy[dir];

      while(xx && yy && xx <= r && yy <= c && vis[xx][yy]) {
        // debug(xx, yy);
        xx += dx[dir];
        yy += dy[dir];
      }
      x = xx;
      y = yy;
      vis[x][y] = true;
      // debug(x, y);
    }
    cout << "Case #" << t << ": " << x << " " << y << '\n'; 
  }
  return 0;
}