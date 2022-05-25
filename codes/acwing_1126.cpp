#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int N = 2005, M = 2*1e5 + 10;

struct edge {
  int v;
  double w;
  int next;
} e[M];

int head[N], cnt;

int n, m;
int A, B;

double dis[N];
bool vis[N];

typedef pair<double, int> PDI;

void add(int a, int b, double c) {
  e[++cnt] = {b, c, head[a]};
  head[a] = cnt;
}
void dijkstra() {
  priority_queue<PDI> q;
  dis[A] = 1;
  q.push({1, A});
  
  while(q.size()) {
    PDI tmp = q.top();
    q.pop();
    int u = tmp.second;
    if(vis[u]) continue;
    vis[u] = true;

    if(u == B) break;

    for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      double w = e[i].w;
      if(dis[v] < dis[u]*w) {
        dis[v] = dis[u]*w;
        q.push({dis[v], v});
      }
    }
  }
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  FOR(i, 1, m) {
    int a, b;
    double c;
    cin >> a >> b >> c;
    add(a, b, (100.0 - c)/100), add(b, a, (100.0 - c)/100);
  }
  cin >> A >> B;
  dijkstra();
  printf("%.8lf", 100.0/dis[B]);
  return 0;
}
#endif