#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 25005, M = 150005, INF = 0x3f3f3f3f;


int t, r, p, s;
int dis[N];
bool vis[N];
int head[N], cnt;
int cc[N], cccnt, ind[N];
typedef pair<int, int> PII;

vector<int> ccv[N];
queue<int> q;

struct edge {
  int v, w, next;
} e[M];

void add(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

void dfs(int u) {
  cc[u] = cccnt;
  ccv[cccnt].push_back(u);
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if(!cc[v]) {
      dfs(v);
    }
  }
}

void dijkstra(int ccid) {
  // memset(vis, 0, sizeof vis);
  priority_queue<PII, vector<PII>, greater<PII>> pq;

  for(auto v:ccv[ccid]) {
    pq.push({dis[v], v});
  }

  while(pq.size()) {
    int u = pq.top().second;

    // cout << u << ":" << pq.top().first << endl;

    pq.pop();

    if(vis[u]) continue;
    vis[u] = true;

    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v, w = e[i].w;
      if(ccid != cc[v]) {
        ind[cc[v]]--;
        if(!ind[cc[v]]) q.push(cc[v]);
      }
      if(dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if(ccid == cc[v]) pq.push({dis[v], v});
      }
    }
  }
  // cout << endl;
}

void topological() {
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0;

  FOR(ccid, 1, cccnt) {
    if(ind[ccid] == 0) q.push(ccid);
  }

  while(q.size()) {
    int u = q.front();
    q.pop();
    dijkstra(u);
  }
}

#ifdef LEET
#include "leet.h"
#else
int main() {

  scanf("%d%d%d%d", &t, &r, &p, &s);

  FOR(i, 1, r) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }

  FOR(i, 1, t) {
    if(cc[i] == 0) {
      ++cccnt;
      dfs(i);
    }
  }

  FOR(i ,1, p) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c);
    ind[cc[b]]++;
  }
  topological();
  FOR(i, 1, t) {
    if(dis[i] >= INF/2) {
      puts("NO PATH");
    } else {
      printf("%d\n", dis[i]);
    }
  }
  return 0;
}

#endif