#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 105, V = 105;
int n, vv;

int head[N], cnt;
int v[N], w[N];

int f[N][V];

struct edge {
  int v, w, next;
} e[N - 1];

void add(int a, int b, int c) {
  e[++cnt] = {b, c, head[a]};
  head[a] = cnt;
}

void dfs(int u) {

  FOR(i, v[u], vv) f[u][i] = w[u];

  for(int i = head[u]; i; i = e[i].next) {
    int to = e[i].v;
    dfs(to);
    for(int j = vv; j >= v[u]; j--) {
      FOR(k, 0, j - v[u]) {
        f[u][j] = max(f[u][j], f[u][j-k] + f[to][k]);
      }
    }
  }
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> vv;
  int root = -1;
  FOR(i, 1, n) {
    int p;
    cin >> v[i] >> w[i] >> p;
    if(p == -1) root = i;
    else add(p, i, 1);
  }
  dfs(root);
  cout << f[root][vv];
  return 0;
}
#endif