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

int V, E;
edge e2[maxE];
int head2[maxV], cnt2;

void addE2(int u, int v, int w) {
  e2[++cnt2] = {u, v, w, head2[u]};
  head2[u] = cnt2;
}

bool vis[maxV];
vector<int> mapping;

void dfs(int u) {
  vis[u] = 1;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(!vis[v]) dfs(v);
  }
  mapping.push_back(u);
}

int scc[maxV], scccnt;

void dfs2(int u) {
  scc[u] = scccnt;
  for(int i = head2[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(!scc[v]) dfs2(v);
  }
}

int main() {
  cin >> V >> E;
  FOR(i, 1, V) {
    int u, v;
    cin >> u >> v;
    addE(u, v, 1);
    addE2(v, u, 1);
  }

  FOR(i, 1, V){
    if(!vis[i]) dfs(i);
  }

  _FOR(i, V, 1) {
    if(!scc[mapping[i]]) {
      scccnt++;
      dfs2(mapping[i]);
    }
  }

}