#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 11, ST = 1 << 10;

typedef pair<pair<int, int>, int> PIII;

int n, m, p, k;

int g[N][N][N][N];
vector<int> key[N][N];

int s;


int dis[N][N][ST];
bool vis[N][N][ST];

int dijkstra() {
  memset(dis, 0x3f, sizeof dis);
  int st = 0;
  deque<PIII> q;
  if(key[1][1].size() != 0) {
    for(auto k:key[1][1]) {
      st |= (1 << (k - 1));
    }
  }
  dis[1][1][st] = 0;
  q.push_back({{1, 1}, st});

  while(q.size()) {
    PIII tmp = q.front();
    int x = tmp.first.first;
    int y = tmp.first.second;
    int st = tmp.second;

    q.pop_front();

    if(x == n && y == m) return dis[x][y][st];

    if(vis[x][y][st]) continue;
    vis[x][y][st] = true;
    // printf("--%d:%d:%d:%d\n", x, y, st, dis[x][y][st]);

    int oldst = st;
    if(key[x][y].size() != 0) {
      for(auto k:key[x][y]) {
        st |= (1 << (k - 1));
      }
    }

    dis[x][y][st] = min(dis[x][y][st], dis[x][y][oldst]);

    static int dx[4] = {-1, 0, 1, 0};
    static int dy[4] = {0, 1, 0, -1};

    FOR(i, 0, 3) {
      int xx = x + dx[i], yy = y + dy[i];
      if(!xx || !yy || xx > n || yy > m) continue;

      int check = false;
      if(g[x][y][xx][yy] == -1) check = true;
      else if(g[x][y][xx][yy] > 0){
        if(st & (1 << (g[x][y][xx][yy] - 1))) {
          check = true;
        }
      }
      // printf("%d:%d:%d:%d:%d:%d\n", xx, yy, st, check, dis[x][y][st], dis[xx][yy][st]);
      if(check && dis[xx][yy][st] > dis[x][y][st] + 1) {
        dis[xx][yy][st] = dis[x][y][st] + 1;
        q.push_back({{xx, yy}, st});
      }
    }
  }
  return -1;
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  memset(g, -1, sizeof g);
  cin >> n >> m >> p;
  cin >> k;
  FOR(i, 1, k) {
    int x1,y1,x2,y2,gg;
    cin >> x1 >> y1 >> x2 >> y2 >> gg;
    g[x1][y1][x2][y2] = g[x2][y2][x1][y1] = gg;
  }
  cin >> s;
  FOR(i, 1, s) {
    int x, y, q;
    cin >> x >> y >> q;
    key[x][y].push_back(q);
  }
  cout << dijkstra();
  return 0;
}
#endif