#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
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

const int N = 1e4 + 10, M = 5e4 + 10;

int n, m;

int h[N], ecnt;

struct edge {
  int v, next;
} e[M];

void add(int u, int v) {
  e[++ecnt] = {v, h[u]};
  h[u] = ecnt;
}

int cc[N], sz[N], cccnt;
int dfsn[N], low[N], dfscnt;
bool st[N];

int outd[N];
stack<int> s;

void tarjan(int u) {
  dfsn[u] = low[u] = ++ dfscnt;
  st[u] = true;
  s.push(u);
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(!dfsn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if(st[v]) {
      low[u] = min(low[u], dfsn[v]);
    }
  }
  if(dfsn[u] == low[u]) {
    ++cccnt;
    int cur;
    do {
      cur = s.top();
      s.pop();
      st[cur] = false;
      cc[cur] = cccnt;
      sz[cccnt]++;
    } while(cur != u);
  }
}

int main() {
  cin >> n >> m;
  FOR(i, 1, m) {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }
  FOR(u, 1, n) {
    if(!dfsn[u]) {
      tarjan(u);
    }
  }
  FOR(u, 1, n) {
    for(int i = h[u]; i; i = e[i].next) {
      int v = e[i].v;
      int ccu = cc[u], ccv = cc[v];
      if(ccu != ccv) {
        outd[ccu]++;
      }
    }
  }
  int ans = 0, sum = 0;
  FOR(i, 1, cccnt) {
    if(outd[i] == 0) {
      ans++;
      sum += sz[i];
      if(ans > 1) {
      sum = 0;
      break;
    }
    }
  }
  cout << sum;
  return 0;
}
