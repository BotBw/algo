#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int max(int n,...) {va_list args;va_start(args, n);int ret = INT_MIN;FOR(i, 0, n-1)ret = max(ret, va_arg(args, int));va_end(args);return ret;}
int min(int n,...) {va_list args;va_start(args, n);int ret = INT_MAX;FOR(i, 0, n-1)ret = min(ret, va_arg(args, int));va_end(args);return ret;}

int n, m, Q;
const int maxn = 205;
int graph[maxn][maxn];
int t[maxn];
int levelcnt;
#ifdef LEET
#include "leet.h"

#else
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  memset(graph, 0x3f, sizeof(graph));
  FOR(i, 0, n-1) {
    cin >> t[i];
  }
  FOR(i, 1, m) {
    int x, y, w;
    cin >> x >> y >> w;
    graph[x][y] = graph[y][x] = min(graph[x][y], w);
  }
  FOR(i, 0, n-1) {
    graph[i][i] = 0;
  }
  cin >> Q;
  int cur = 0;
  FOR(q, 1, Q) {
    int x, y, tt;
    cin >> x >> y >> tt;
    while(t[cur] <= tt && cur <= n-1) {
      FOR(i, 0, n-1) {
        FOR(j, 0, n-1) {
          graph[j][i] = graph[i][j] = min(graph[i][j], graph[i][cur] + graph[cur][j]);
        }
      }
      cur++;
    }
    if(t[x] > tt || t[y] > tt) {
      cout << -1 << endl;
      continue;
    }
    cout << (graph[x][y] == 0x3f3f3f3f ? -1 : graph[x][y]) << endl;
  }  
  return 0;
}
#endif