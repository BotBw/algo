#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#endif

const int N = 1e5 + 5;

struct edge {
  int v, w, nxt;
} e[N-1];

int n;

int h[N], cnt;
void add(int a, int b, int c) {
  e[++cnt] = {b, c, h[a]};
  h[a] = cnt;
}

int down[N], down1[N], up[N], pa[N];

int ans = 0x3f3f3f3f;

void dfs1(int u, int fa) {
  for(int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].v, w = e[i].w;
    if(v == fa) continue;

    if(v != pa[u]) up[v] = max(up[u], down[u]) + w;
    else up[v] = max(up[u], down1[u]) + w;

    ans = min(ans, max(down[v], up[v]));

    dfs1(v, u);
  }
}

void dfs(int u, int fa) {
  for(int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].v, w = e[i].w;
    if(v == fa) continue;
    dfs(v, u);
    if(down[v] + w >= down[u]) {
      pa[u] = v;
      down1[u] = down[u];
      down[u] = down[v] + w;
    } else if(down[v] + w > down1[u]) {
      down1[u] = down[v] + w;
    }
  }
}

int main() {
  cin >> n;

  FOR(i, 1, n-1) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
    add(b, a, c);
  }

  dfs(1, -1);
  ans = max(down[1],down1[1]);
  dfs1(1, -1);

  cout << ans;
  return 0;
}
