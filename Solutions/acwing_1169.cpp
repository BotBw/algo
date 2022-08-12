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

const int N = 100005, M = 100005 * 3;

int h[N], ecnt;
int n, m;


struct edge {
  int v, w, next;
} e[M];

void add(int u, int v, int w) {
  e[++ecnt] = {v, w, h[u]};
  h[u] = ecnt;
}

LL dis[N];
int pcnt[N];
int s[N], hh = 0, tt = -1;
bool st[N];

LL spfa() {
  s[++tt] = 0;
  st[0] = 1;

  while(hh <= tt) {
    int u = s[tt--];
    // printf("%d ", u);
    st[u] = 0;
    for(int i = h[u]; i; i = e[i].next) {
      int v = e[i].v, w= e[i].w;
      if(dis[v] < dis[u] + w) {
        dis[v] = dis[u] + w;
        pcnt[v] = pcnt[v] + 1;
        if(pcnt[v] == n) return -1;
        if(!st[v]) {
          st[v] = 1;
          s[++tt] = v;
        }
      }
    }
  }
  LL ans = 0;
  FOR(i, 1, n) {
    ans += dis[i];
  }
  return ans;
}



int main() {
  cin >> n >> m;
  FOR(i, 1, m) {
    int t, a, b;
    cin >> t >> a >> b;
    // dis[v] >= dis[u] + w;
    switch(t) {
      case 1: // a == b
        add(a, b, 0);
        add(b, a, 0);
        break;
      case 2: // a < b
        add(a, b, 1);
        break;
      case 3: // a >= b
        add(b, a, 0);
        break;
      case 4: // a > b
        add(b, a, 1);
        break;
      case 5: // a <= b;
        add(a, b, 0);
        break;
    }
  }
  // dis[x] >= 1
  FOR(v, 1, n) {
    add(0, v, 1);
  }

  cout << spfa();

  return 0;
}
