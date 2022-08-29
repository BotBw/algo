#include "bits/stdc++.h"

class Solution {
public:
    void bfs(vector<vector<bool>> &g, vector<vector<bool>> &vis, int i, int j) {
      int n = g.size() - 1, m = g[0].size() - 1;
      vis[i][j] = true;
      queue<pii> q;
      q.push({i, j});
      int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
      while(q.size()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        FOR(k, 0, 3) {
          int xx = x + dx[k], yy = y + dy[k];
          if(xx >= 0 && xx <= n && yy >= 0 && yy <= m && !vis[xx][yy] && g[xx][yy]) {
            vis[xx][yy] = true;
            q.push({xx, yy});
          }
        }
      }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> g(n + 1, vector<bool>(m + 1));
        auto vis = g;
        FOR(i, 1, n) {
          FOR(j, 1, m) {
            g[i][j] = grid[i-1][j-1] == '1';
          }
        }
        int res = 0;
        FOR(i, 1, n) {
          FOR(j, 1, m) {
            if(g[i][j] && !vis[i][j]) bfs(g, vis, i, j), res++;
          }
        }
        return res;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}