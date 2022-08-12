#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
typedef long long LL;
typedef pair<LL, LL> PLL;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

const int N = 3e5 + 10;

int h[N], ecnt;

struct edge {
  int v, next;
} e[N * 2];

void add(int a, int b) {
  e[++ecnt] = {b, h[a]};
  h[a] = ecnt;
}

int sz[N];
int n;
int f[N];

void dfs(int u, int fa) {
  f[u] = 0;
  sz[u] = 1;
  int sum = 0;
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(v == fa) continue;
    dfs(v, u);
    sum += f[v];
    sz[u] += sz[v];
  }
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(v == fa) continue;
    f[u] = max(f[u], sz[v] - 1 + sum - f[v]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    memset(h, 0, sizeof h);
    ecnt = 0;
    cin >> n;
    FOR(i, 1, n-1) {
      int u, v;
      cin >> u >> v;
      add(u, v);
      add(v, u);
    }
    dfs(1, 0);
    cout << f[1] << '\n';
  }
  return 0;
}