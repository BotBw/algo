#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 105;

int g[N][N], n, m;
int f[N][N], pre[N][N];

int path[N], cnt;

void get_path(int i, int j) {
  if(pre[i][j] == 0) {
    return;
  }
  int k = pre[i][j];
  get_path(i, k);
  path[++cnt] = k;
  get_path(k, j);
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  memset(g, 0x3f, sizeof g);

  cin >> n >> m;

  FOR(i, 1, n) g[i][i] = 0;

  FOR(i, 1, m) {
    int u, v, l;
    cin >> u >> v >> l;
    g[u][v] = g[v][u] = min(g[u][v], l);
  }

  memcpy(f, g, sizeof g);

  LL ans = 0x3f3f3f3f;

  FOR(k, 1, n) {
    FOR(i, 1, k-1) {
      FOR(j, i + 1, k-1) {
        LL t = (LL)f[i][j] + g[i][k] + g[j][k];
        if(ans > t) {
          ans = t;
          cnt = 0;
          path[++cnt] = k;
          path[++cnt] = i;
          get_path(i, j);
          path[++cnt] = j;
        }
      }
    }
    FOR(i ,1, n) 
      FOR(j, 1, n) {
        int t = f[i][k] + f[k][j];
        if(f[i][j] > t) {
          f[i][j] = t;
          pre[i][j] = k;
        }
      }
  }
  if(ans == 0x3f3f3f3f) puts("No solution.");
  else FOR(i, 1, cnt) cout << path[i] << " ";

  return 0;
}
#endif