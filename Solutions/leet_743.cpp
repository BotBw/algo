#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#ifdef LEET
#include "leet.h"
class Solution {
public:
    struct node {
        int x, dis;
    };
    struct edge {
        int to, dis;
    };
    int networkDelayTime(vector<vector<int>>& es, int n, int k) {
        vector<vector<edge>> g(n + 1);
        vector<int> dis(n + 1, 0x3f3f3f3f);
        vector<bool> st(n + 1, 0);
        queue<node> q;
        for(auto e:es) {
            g[e[0]].push_back({e[1], e[2]});
        }
        q.push({k, 0});
        dis[k] = 0;
        st[k] = 1;
        while(!q.empty()) {
            auto frt = q.front(); q.pop();
            int x = frt.x, diss = frt.dis;
            // printf("%d:%d\n", x, diss);
            st[x] = false;
            for(auto e:g[x]) {
                if(dis[e.to] > dis[x] + e.dis) {
                    dis[e.to] = dis[x] + e.dis;
                    if(!st[e.to]) {
                        st[e.to] = true;
                        q.push({e.to, dis[e.to]});
                    }
                }
            }
        }
        int maxdis = 0;
        for(int i = 1; i <= n; i++) {
            if(dis[i] == 0x3f3f3f3f) return -1;
            maxdis = max(maxdis, dis[i]);
        }
        return maxdis;
    }
};
#else
int main() {
  return 0;
}
#endif