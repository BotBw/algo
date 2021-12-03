#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

#define maxV 1000
#define maxE 10000

#ifdef maxV
#ifdef maxE
int head[maxV], cnt;

struct edge {
  int u, v, w, next;
} e[maxE];

void addE(int u, int v, int w) {
  e[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}
#endif
#endif

int E, V;

int timer, sccCnt;
int dfsn[maxV], vis[maxV], low[maxV], instack[maxV];
int scc[maxV], sz[maxV];

stack<int> s;
void tanjan(int u) {
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(!vis[v]) {
      vis[v] = 1;
      dfsn[v] = ++timer;
      instack[v] = 1;
      tanjan(v);
      low[u] = min(low[u], low[v]);
    } else if(instack[v]) {
      low[u] = min(low[u], dfsn[u]);
    }
  }
  if(low[u] == dfsn[u]) {
    ++sccCnt;
    while(s.top() != u) {
      scc[s.top()] = sccCnt;
      sz[sccCnt]++;
      instack[s.top()] = 0;
      s.pop();
    }
    scc[s.top()] = sccCnt;
    sz[sccCnt]++;
    instack[s.top()] = 0;
    s.pop();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> V >> E;
  for(int i = 1; i <= E; i++) {
    int u, v;
    cin >> u >> v;
    addE(u, v, 1);
  }
  FOR(i, 1, V) {
    if(!vis[i]) {
      vis[i] = 1;
      dfsn[i] = ++timer;
      instack[i] = 1;
      tanjan(i);
    }
  }
  return 0;
}