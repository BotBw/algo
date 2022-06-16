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


const int N = 105, M = N*N;

int h[N], ecnt;

int n;

struct edge {
  int v, next;
} e[M];

void add(int u, int v) {
  e[++ecnt] = {v, h[u]};
  h[u] = ecnt;
}

int cc[N], cccnt, ind[N], outd[N];
int dfsn[N], low[N], dfscnt;
bool st[N];
stack<int> s;

void tarjan(int u) {
  dfsn[u] = low[u] = ++ dfscnt;
  st[u] = true, s.push(u);
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
    cccnt++;
    int cur;
    do {
      cur = s.top(), s.pop(), st[cur] = false;
      cc[cur] = cccnt;
    } while(cur != u);
  }
}


int main() {
  cin >> n;
  FOR(i, 1, n) {
    int v;
    while(cin >> v && v) {
      add(i, v);
    }
  }
  FOR(u, 1, n ) {
    if(!dfsn[u]) {
      tarjan(u);
    }
  }
  FOR(u, 1, n){
    for(int i = h[u]; i; i = e[i].next) {
      int v = e[i].v;
      int ccu = cc[u], ccv = cc[v];
      if(ccu != ccv) {
        ind[ccv]++;
        outd[ccu]++;
      }
    }
  }
  int in_cnt = 0, out_cnt = 0;
  FOR(i, 1, cccnt) {
    if(!ind[i]) in_cnt++;
    if(!outd[i]) out_cnt++;
  }
  cout << in_cnt << endl << (cccnt == 1 ? 0 : max(in_cnt, out_cnt));
  return 0;
}
