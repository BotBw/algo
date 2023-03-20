#include "bits/stdc++.h"

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
      return dfs(0, 0, grid, 0);
    }

    bool dfs(int x, int y, vector<vector<int>> &g, int cnt) {
      int n = g.size();
      if(g[x][y] == n * n - 1 && cnt == n*n -1) return true;
      int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
      int dy[] = {-2, -1, 1, 2, 2 ,1 ,-1 ,-2};
      FOR(k, 0, 7) {
        int xx = x + dx[k], yy = y + dy[k];
        if(xx < 0 || yy < 0 || yy >= n || xx >= n) continue;
        if(g[xx][yy] != g[x][y] + 1) continue;
        if(dfs(xx, yy, g, cnt + 1)) return true;
      }
      return false;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}