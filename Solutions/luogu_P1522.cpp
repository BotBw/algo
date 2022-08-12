#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

int N;
const int maxn = 155;
const int DBL_INF = (DBL_MAX/2);
struct cord {
  int x, y;
} cor[maxn];

bool graph[maxn][maxn];
double f[maxn][maxn];
int dfsn[maxn];
bool vis[maxn];
int dfscnt;
double possible_dia[maxn];
double dia_dfsn[maxn];
void dfs(int i) {
  FOR(j, 1, N) {
    if(!graph[i][j]) continue;
    if(!vis[j]) {
      vis[j] = true;
      dfsn[j] = dfscnt;
      dfs(j);
    }
  }
}

double dis(cord a, cord b) {
  int dx = b.x - a.x;
  int dy = b.y - a.y;
  return sqrt(dx*dx + dy*dy);
}

void read() {
  cin >> N;
  FOR(i, 1, N) {
    cin >> cor[i].x >> cor[i].y;
  }
  FOR(i, 1, N) {
    string s;
    cin >> s;
    for(int j = 1; j <= N; j++) {
      graph[i][j] = s[j-1] == '0' ? 0 : 1;
    }
  }
}

void init() {
  FOR(i, 1, N)
    FOR(j, 1, N)
      f[i][j] = DBL_INF;
  FOR(i, 1, N) {
    FOR(j, i, N) {
      if(graph[i][j])
        f[i][j] = f[j][i] = dis(cor[i], cor[j]);
    }
  }
  FOR(i, 1, N) f[i][i] = 0;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  read();
  init();
  FOR(i, 1, N) {
    if(!vis[i]) {
      dfscnt++;
      vis[i] = true;
      dfsn[i] = dfscnt;
      dfs(i);
    }
  }
  FOR(k, 1, N) {
    FOR(i, 1, N) {
      FOR(j, 1, N) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }

  FOR(i, 1, N) {
    FOR(j, 1, N) {
      if(f[i][j] != DBL_INF) {
        possible_dia[i] = max(possible_dia[i], f[i][j]);
      }
    }
    dia_dfsn[dfsn[i]] = max(dia_dfsn[dfsn[i]], possible_dia[i]);
  }
  
  double ans = DBL_INF;
  double ifConnnected = 0;

  FOR(i, 1, N) {
    FOR(j, i+1, N) {
      if(dfsn[i] != dfsn[j]) {
        ifConnnected = max(
          max(dia_dfsn[dfsn[i]], dia_dfsn[dfsn[j]]),
          possible_dia[i] + dis(cor[i], cor[j]) + possible_dia[j]
        );
        ans = min(ans, ifConnnected);
      }
    }
  }
  printf("%.6f", ans);
  #ifdef DEBUG
  FOR(i,1,N) {
    FOR(j,1,N)
      cout << f[i][j] << ' ';
    cout << endl;
  }
  #endif
  return 0;
}
#endif