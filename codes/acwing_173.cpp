#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxn = 1005;
bool g[maxn][maxn], vis[maxn][maxn];

int b[maxn][maxn];
int n, m;
queue<PII> q;

int d[] = {1, 0, -1, 0, 1};

void bfs() {
  while(!q.empty()) {
    auto frt = q.front(); q.pop();
    int x = frt.first, y = frt.second;
    FOR(k, 1, 4) {
      int xx = x + d[k-1], yy = y + d[k];
      if(xx < 1 || yy < 1 || xx > n || yy > m) continue;
      if(vis[xx][yy]) continue;
      b[xx][yy] = b[x][y] + 1;
      vis[xx][yy] = true;
      q.push({xx, yy});
    }
  }
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  FOR(i, 1, n) {
   string s;
   cin >> s;
   FOR(j, 1, m) {
     g[i][j] = (s[j-1] == '1');
     if(g[i][j] == true) {
       vis[i][j] = true;
       q.push({i, j});
     }
   }
  }
  bfs();
  FOR(i, 1, n) {
    FOR(j, 1, m) {
       cout << b[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
#endif