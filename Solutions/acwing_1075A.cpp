#include "bits/stdc++.h"

int getY(int x) {
  int y = 1;
  for(int i = 2; i <= x/i; i++) {
    if(x % i == 0) {
      y += i;
      if((x / i) != i) y += x/i;
    }
  }
  return y;
}
const int N = 50005;
int n;

struct edge {
  int v, w, ne;
} e[N * 2];

int h[N], cnt;
bool vis[N];

void add(int a, int b, int c) {
  e[++cnt] = {b, c, h[a]};
  h[a] = cnt;
}

int u1, max1;

void dfs1(int u, int cur, int pre) {
  vis[u] = true;
  if(cur > max1) {
    max1 = cur;
    u1 = u;
  }
  for(int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v, w = e[i].w;
    if(pre == v) continue;
    dfs1(v, cur + w, u);
  }
}

int ans = 0;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  FOR(x, 2, n) {
    int y = getY(x);   
    debug(x, y);
    if(!y) continue;
    if(y < x) {
      add(x, y, 1);
      add(y, x, 1);
    }
  }
  FOR(i, 1, n) {
    if(!vis[i]) {
      max1 = 0;
      dfs1(i, 0, 0);
      max1 = 0;
      dfs1(u1, 0, 0);
      ans = max(max1, ans);
    }
  }
  cout << ans << endl;
  return 0;
}