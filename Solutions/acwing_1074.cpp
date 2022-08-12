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

const int Q = 105, N = 105;

struct edge {
  int v, w, next;
} e[N*2];
int h[N], cnt;
void add(int a, int b, int c) {
  e[++cnt] = {b, c, h[a]};
  h[a] = cnt;
}
int n, q;
int f[N][Q];

void dfs(int fa, int u) {
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v, w = e[i].w;
    if(v == fa) continue;
    dfs(u, v);
    _FOR(j, q, 1) {
      FOR(k, 0, j-1) {
        f[u][j] = max(f[u][j], f[u][j - k - 1] + f[v][k] + w);
      }
    }
  }
}
int main() {
  cin >> n >> q;
  FOR(i, 1, n-1) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
    add(b, a, c);
  }
  dfs(-1, 1);
  cout << f[1][q];
  return 0;
}
