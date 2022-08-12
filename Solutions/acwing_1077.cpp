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

// f[u][st]
// f[u][0] = sum{f[v][1]};
// f[u][1] = sum{min(f[v][1], f[v][2])} 1 个f[v][2]
// f[u][2] = w[u] + min{sum{f[v][2/1/0]}}

const int N = 1505;

int n;
int w[N];
LL f[N][3];
bool notRt[N];

int h[N], ecnt;

struct edge {
  int v, next;
} e[N];

void add(int u, int v) {
  e[++ecnt] = {v, h[u]};
  h[u] = ecnt;
}

void dfs(int u) {
  bool st = false;
  LL diff = 0x3f3f3f3f;
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v;
    dfs(v);
    f[u][0] += f[v][1];
    if(f[v][2] <= f[v][1]) {
      st = true;
      f[u][1] += f[v][2];
    } else {
      diff = min(diff, f[v][2] - f[v][1]);
      f[u][1] += f[v][1];
    }
    f[u][2] += min(f[v][0], min(f[v][1], f[v][2]));
  }
  if(!st) {
    f[u][1] += diff;
  }
  f[u][2] += w[u];
}

int main() {
  cin >> n;
  FOR(i, 1, n) {
    int u, k, m;
    cin >> u >> k >> m;
    w[u] = k;
    FOR(j, 1, m) {
      int v;
      cin >> v;
      add(u, v);
      notRt[v] = true;
    }
  }
  int rt = 0;
  FOR(i, 1, n) {
    if(!notRt[i]) {
      rt = i;
      dfs(rt);
      break;
    }
  }
  cout << min(f[rt][1], f[rt][2]);
  return 0;
}
