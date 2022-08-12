#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

typedef pair<int, int> PII;
const int maxn = 55;

int g[maxn][maxn];

int m, n;

bool vis[maxn][maxn];

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int bfs(int i, int j) {
  int area = 1;
  queue<PII> q;
  q.push({i, j});
  vis[i][j] = true;

  while (!q.empty()) {
    auto frt = q.front(); q.pop();
    int x = frt.first, y = frt.second;
    for(int k = 0; k < 4; k++) {
      int xx = x + dx[k], yy = y + dy[k];
      if(vis[xx][yy]) continue;
      bool wall = (g[x][y] >> k) & 1;
      if(wall) continue;
      vis[xx][yy] = true;
      q.push({xx, yy});
      area++;
    }
  }
  return area;
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> m >> n;
  FOR(i, 1, m) {
    FOR(j, 1 ,n) {
      cin >> g[i][j];
    }
  }
  int area = 0, cnt = 0;
  FOR(i, 1, m) {
    FOR(j, 1, n) {
      if(!vis[i][j]) {
        area = max(area, bfs(i, j));
        cnt++;
      }
    }
  }
  cout << cnt << endl << area;
  return 0;
}
#endif