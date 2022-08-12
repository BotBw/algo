#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG
#define maxV 1000
#define maxE 10000*2

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

int dfsn[maxV], dfscnt;
int low[maxV];
vector<int> cut_vertex;
void tarjan(int u, bool root) {
  int count = 0;
  dfsn[u] = low[u] = ++dfscnt;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(!dfsn[v]) {
      tarjan(v, false);
      low[u] = min(low[u], low[v]);
      count += (low[u] >= dfsn[v]);
    } else {
      low[u] = min(low[u], dfsn[v]);
    }
  }
  if(count > root) {
    cut_vertex.push_back(u);
  }
}
vector<edge> ans;
void tarjan(int u, int fa) {
  dfsn[u] = low[u] = ++dfscnt;
  for(int i = head[u]; i ; i = e[i].next) {
    int v = e[i].v;
    if(!dfsn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if(low[u] > low[v]) {
        ans.emplace_back(u, v, 1);
      }
    } else if(v != fa) {
      low[u] = min(low[u], dfsn[v]);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> V >> E;
  FOR(i, 1, E) {
    int u, v;
    cin >> u >> v;
    addE(u, v, 0);
    addE(v, u, 0); // undirected
  }

}