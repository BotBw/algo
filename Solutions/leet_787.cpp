#include "bits/stdc++.h"

class Solution {
public:
    vector<int> h;

    struct edge {
      int v, w ,ne;
    };
    vector<edge> es;

    void adde(int u, int v, int w) {
      es.push_back({v, w, h[u]});
      h[u] = es.size() - 1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      h = vector<int>(n, -1);
      es = vector<edge>();

      for(auto &v : flights) adde(v[0], v[1], v[2]);

      vector<vector<int>> dis(n, vector<int>(k + 1, LLONG_INF));

      dis[src][0] = 0;

      queue<pii> q;

      q.push({src, 0});

      while(q.size()) {
        auto cur = q.front();
        int u = cur.first, kk = cur.second;
        q.pop();

        for(int i = h[u]; ~i; i = es[i].ne) {
          int v = es[i].v, w = es[i].w;
          if(v == dst) {
            dis[v][kk] = min(dis[v][kk], dis[u][kk] + w);
          } else if(kk + 1 <= k && dis[v][kk + 1] > dis[u][kk] + w) {
            dis[v][kk + 1] = dis[u][kk] + w;
            q.push({v, kk + 1});
          }
        }
      }
      
      int ans = LLONG_INF;

      FOR(kk, 0, k) ans = min(ans, dis[dst][kk]);

      if(ans == LLONG_INF) ans = -1;

      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}