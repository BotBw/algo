#include <bits/stdc++.h>
using namespace std;

const int N = 255;
typedef pair<int, int> PII;

char grid[N][N];

int r, c;

int dis[N][N];
bool vis[N][N];

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int max(int a, int b, int c, int d) {
  return max(max(a, b), max(c, d));
}

int bfs() {
  int ret = 0;
  queue<PII> q;
  for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
      if(grid[i][j] == '1') {
        q.push({i, j});
        vis[i][j] = 1;
        dis[i][j] = 0;
      }
  if(q.empty()) return c + r;
  while(q.size()) {
    PII u = q.front();
    int x = u.first, y = u.second;
    q.pop();
    for(int k = 0; k < 4; k++) {
      int xx = x + dx[k], yy = y + dy[k];
      if(!xx || !yy || xx > r || yy > c || vis[xx][yy]) continue;
      vis[xx][yy] = 1;
      dis[xx][yy] = dis[x][y] + 1;
      ret = max(dis[xx][yy], ret);
      q.push({xx, yy});
    }
  }
  return ret;
}
// 0              1
// MHTD[(x1, y1), (x2, y2)] = QIED[(x1 + y1, x1 - y1), (x2 + y2, x2 - y2)]
// max(|x1 + y1 - (x2 + y2)|, |x1 - y1 - (x2 - y2)|)
int diff_min, diff_max, sum_min, sum_max;

bool check(int val) {
  diff_max = sum_max = -0x3f3f3f3f;
  diff_min = sum_min = 0x3f3f3f3f;
  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= c; j++) {
      if(dis[i][j] <= val) continue;
      diff_min = min(diff_min, i - j);
      sum_min = min(sum_min, i + j);
      diff_max = max(diff_max, i - j);
      sum_max = max(sum_max, i + j);
    }
  }
  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= c; j++) {
        int ans = 0;
        ans = max(abs(sum_max - (i + j)), abs((i + j) - sum_min), abs(diff_max - (i - j)), abs((i - j) - diff_min));
        if(ans <= val) return true;
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) scanf("%s", &grid[i][1]);
    int ri = bfs();
    int le = 0;
    
    while(le < ri) {
      int mi = (le + ri) >> 1;
      if(check(mi)) {
        ri = mi;
      } else {
        le = mi + 1;
      }
    }
    printf("Case #%d: %d\n", t, le);
  }
  return 0;
}