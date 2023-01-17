#include "bits/stdc++.h"

const int N = 1505;
int n;

int h[N], cnt;
struct {
  int v, w, ne;
} e[N * 2];

void add(int u, int v, int w) {
  e[++cnt] = {v, w, h[u]};
  h[u] = cnt;
}

int f[N][2];


void dfs(int u, int fa) {
  f[u][0] = 0;
  f[u][1] = 1;
  for(int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if(v == fa) continue;
    dfs(v, u);
    f[u][0] += f[v][1];
    f[u][1] += min(f[v][0], f[v][1]);
  }
}


signed main() {
  // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  while(cin >> n) {
    memset(h, 0, sizeof h);
    // memset(f, 0, sizeof f);
    cnt = 0;
    FOR(i, 1, n) {
      int u, m;
      scanf("%d:(%d)", &u, &m);
      FOR(j, 1, m) {
        int v;
        cin >> v;
        add(u, v, 1);
        add(v, u, 1);
      }
    }
    dfs(1, -1);
    cout << min(f[1][0], f[1][1]) << endl;
  }
  return 0;
}