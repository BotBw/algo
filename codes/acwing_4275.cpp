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

const int N = 1005, M = 2e5 + 10;

int h[N], ecnt;
int a[N], b[N];
int n, m;
typedef pair<int, int> PII;

struct edge {
  int v, w, next;
} e[M];

void add(int a, int b, int c) {
  e[++ecnt] = {b, c, h[a]};
  h[a] = ecnt;
}

int dis[N][N];
int st[N];

void dijkstra(int dis[], int s) {
  memset(st, 0, sizeof st);
  priority_queue<PII, vector<PII>, greater<PII>> q;
  dis[s] = 0;
  q.push({0, s});

  while(q.size()) {
    int u = q.top().second;
    q.pop();

    if(st[u]) continue;
    st[u] = true;

    for(int i = h[u]; i; i = e[i].next) {
      int v = e[i].v, w = e[i].w;
      if(dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

bool check(int dis[]) {
  FOR(i, 1, n) {
    b[i] = dis[a[i]];
    if(b[i-1] > b[i]) return false;
  }
  return true;
}


int main() {
  cin >> n >> m;
  FOR(i, 1, m) {
    int a, b ,c;
    cin >> a >> b >> c;
    add(a, b, c); add(b, a, c);
  }
  memset(dis, 0x3f, sizeof dis);
  int k;
  cin >> k;
  FOR(i, 1, k) {
    FOR(i, 1, n) {
      cin >> a[i];
    }
    if(dis[a[1]][a[1]] != 0) {
      dijkstra(dis[a[1]], a[1]);
    }
    if(check(dis[a[1]])) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
