#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#include "leet.h"
#include "mySTL.h"
#else
#define debug(...)
#endif
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class Solution {
public:
    struct edge {
      int v, c, ne;
    };
    vector<edge> e;
    vector<int> h;

    void add(int u, int v ,int c) {
      e.push_back({v, c, h[u]});
      h[u] = e.size() - 1;
    }

    vector<int> bfs(int n, int st) {
      vector<vector<int>> dis(n, vector<int>(2, INT_INF));
      queue<pii> q;
      q.push({st, 0});
      q.push({st, 1});
      dis[st][0] = 0;
      dis[st][1] = 0;
      while(q.size()) {
        auto cur = q.front(); q.pop();
        int u = cur.first, color = cur.second;
        int preC = (color + 1) % 2;
        for(int i = h[u]; ~i; i = e[i].ne) {
          int v = e[i].v, c = e[i].c;
          if(c != color) continue;
          if(dis[u][preC] + 1 >= dis[v][c]) continue;
          dis[v][c] = dis[u][preC] + 1;
          q.push({v, preC});
        }
      }
      vector<int> ans(n);
      FOR(i, 0, n-1) {
        ans[i] = min(dis[i][0], dis[i][1]);
        if(ans[i] == INT_INF) ans[i] = -1;
      }
      return ans;
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        h = vector<int>(n, -1);
        for(auto e:redEdges) add(e[0], e[1], 0);
        for(auto e:blueEdges) add(e[0], e[1], 1);
        return bfs(n, 0);
    }
};

