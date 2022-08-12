#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxn = 1005;

int g[maxn][maxn];
bool vis1[maxn][maxn], vis2[maxn][maxn];
const int INF = 0x3f3f3f3f;
int n;


int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool bfsp(int i, int j) {
  vis1[i][j] = 1;
  queue<PII> q;
  q.push({i, j});
  bool ret = true;
  while(!q.empty()) {
    auto frt = q.front(); q.pop();
    int x = frt.first, y = frt.second;
    for(int k = 0; k < 8; k++) {
      int xx = x + dx[k], yy = y + dy[k];
      if(g[xx][yy] > g[x][y]) {
        ret = false;
        continue;
      }
      if(g[xx][yy] < g[x][y]) continue;
      if(!vis1[xx][yy]) {
        vis1[xx][yy] = true;
        q.push({xx, yy});
      }
    }
  }
  return ret;
}

bool bfsv(int i, int j) {
  vis2[i][j] = 1;
  queue<PII> q;
  q.push({i, j});
  bool ret = true;
  while(!q.empty()) {
    auto frt = q.front(); q.pop();
    int x = frt.first, y = frt.second;
    for(int k = 0; k < 8; k++) {
      int xx = x + dx[k], yy = y + dy[k];
      if(g[xx][yy] < g[x][y]) {
        ret = false;
        continue;
      }
      if(g[xx][yy] > g[x][y]) continue;
      if(!vis2[xx][yy]) {
        vis2[xx][yy] = true;
        q.push({xx, yy});
      }
    }
  }
  return ret;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n;
  FOR(i, 1, n) {
    FOR(j, 1, n) {
      cin >> g[i][j];
    }
  }
  int peek = 0, valley = 0;
  FOR(i, 1, n) {
    FOR(j, 1, n) {
      if(!vis1[i][j]) {
        if(bfsp(i, j)) {
          peek++;
        }
      }
    }
  }
  FOR(i, 0, n+1) g[i][0] = g[i][n+1] = INF;
  FOR(j, 0, n+1) g[0][j] = g[n+1][j] = INF;
  FOR(i, 1, n) {
    FOR(j, 1, n) {
      if(!vis2[i][j]) {
        if(bfsv(i, j)) {
          valley++;
        }
      }
    }
  }
  cout << peek << ' '<< valley;
  return 0;
}
#endif