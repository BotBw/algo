#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 21;

int a[N];

int n;
bool g[N][N];
bool vis[N];
int ans;
int path[N], pcnt;
int cur[N], ccnt;
void dfs(int u, int cnt) {
  if(cnt > ans) {
    ans = cnt;
    pcnt = ccnt;
    memcpy(path, cur, sizeof cur);
  }
  FOR(v, 1, n) {
    if(g[u][v] && !vis[v]) {
      vis[v] = true;
      cur[++ccnt] = v;
      dfs(v, cnt + a[v]);
      ccnt--;
      vis[v] = false;
    }
  }
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i ,1, n) {
    FOR(j, i + 1, n) {
      cin >> g[i][j];
    }
  }
  FOR(i, 1, n) {
    vis[i] = true;
    ccnt = 1;
    cur[1] = i;
    dfs(i, a[i]);
    vis[i] = false;
  }
  FOR(i, 1, pcnt) cout << path[i] << " ";
  cout << endl << ans;
  return 0;
}
#endif