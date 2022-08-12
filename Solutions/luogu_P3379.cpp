#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = N*2;
int h[N], ecnt;

struct edge {
  int v, next;
} e[M];

void add(int u, int v) {
  e[++ecnt] = {v, h[u]};
  h[u] = ecnt;
}

int jp[N][20];
int logn, dep[N];
int n, m, s;

void init(int u, int fa) {
  dep[u] = dep[fa] + 1;
  jp[u][0] = fa;
  for(int i = 1; i <= logn; i++) jp[u][i] = jp[jp[u][i-1]][i-1];
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(v == fa) continue;
    init(v, u);
  }
}

int lca(int a, int b) {
  if(dep[a] > dep[b]) swap(a, b);
  for(int i = logn; i >= 0; i--) {
    if(dep[a] <= dep[jp[b][i]])
      b = jp[b][i];
  }
  if(a == b) return a;
  for(int i = logn; i >= 0; i--) {
    if(jp[a][i] != jp[b][i]) {
      a = jp[a][i];
      b = jp[b][i];
    }
  }
  return jp[a][0];
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  logn = int(log2(n) + 1.0);
  for(int i = 1; i <= n-1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  init(s, 0);
  for(int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", lca(a, b));
  }
  return 0;
}