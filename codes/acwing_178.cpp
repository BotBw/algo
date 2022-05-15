#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxe = 1005;
// const int maxe = 10;

typedef pair<int, int> PII;
typedef pair<int ,PII> PIII;

int h[maxe], rh[maxe], cnt;

struct edge {
  int to, w, nxt;
} e[maxe*maxe*2];

void add(int h[], int a, int b, int w) {
  e[++cnt] = {b, w, h[a]};
  h[a] = cnt;
}

int n, m;

int s, t, k;

int dis[maxe];
bool vis[maxe];

void dijkstra() {
  priority_queue<PII, deque<PII>, greater<PII>> q;
  q.push({0, t});
  vis[t] = 1;
  dis[t] = 0;

  while(q.size()) {
    auto frt = q.top();
    q.pop();
    int x = frt.first;
    
    if(vis[x]) continue;

    vis[x] = 1;

    for(int i = rh[x]; i; i = e[i].nxt) {
      int to = e[i].to, w = e[i].w;
      if(dis[to] > dis[x] + w) {
        dis[to] = dis[x] + w;
        q.push({dis[to], i});
      }
    }
  }
}

int astar() {
  priority_queue<PIII, deque<PIII>, greater<PIII>> q;

  q.push({dis[s], {0, s}});

  int cnt = 0;

  if(dis[s] == 0x3f3f3f3f) return -1;

  while(q.size()) {
    auto frt = q.top();
    q.pop();
    int x = frt.second.second;
    int dist = frt.second.first;
    if(x == t) cnt++;
    if(cnt == k) return dist;
    for(int i = h[x]; i; i = e[i].nxt) {
      int b = e[i].to, w = e[i].w;
      int nxt = dist + w;
      q.push({nxt + dis[b], {nxt, b}});
    }
  }
  return -1;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> n >> m;
  FOR(i, 1, m) {
    int a,b,l;
    cin>>a>>b>>l;
    add(h, a, b, l);
    add(rh, b, a, l);
  }
  cin>>s>>t>>k;
  if(s==t) k++;
  dijkstra();
  cout << astar();
  return 0;
}
#endif