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

const int N = 100, M = N*2;

int n, m;

int h[N], ecnt;

struct edge {
  int v, next;
} e[M];

void add(int a, int b) {
  e[++ecnt] = {b, h[a]};
  h[a] = ecnt;
}
int cc[N], sz[N], cccnt;
int dfsn[N], low[N], dfscnt;
bool st[N];
stack<int> s;

void tarjan(int u) {
  dfsn[u] = low[u] = ++dfscnt;
  s.push(u);
  st[u] = true;
  for(int i = h[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(!dfsn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if(st[v]) {
      low[u] = min(low[u], dfsn[v]);
    }
  }
  if(low[u] == dfsn[u]) {
    int cur;
    ++cccnt;
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
  FOR(i, 1, n) {
    if(!dfsn[i]) {
      tarjan(i);
    }
  }
  return 0;
}
