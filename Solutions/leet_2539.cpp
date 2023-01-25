#include "bits/stdc++.h"

class Solution {
public:
    void bfs(vector<int> &dis, int st, const vector<int> &e) {
        dis[st] = 0;
        queue<int> q;
        q.push(st);
        while(q.size()) {
            int u = q.front();
            q.pop();
            int v = e[u];
            if(v != -1 && dis[v] == INT_INF) {
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n, INT_INF), dis2(n, INT_INF);
        bfs(dis1, node1, edges);
        bfs(dis2, node2, edges);
        int res = -1, minD = INT_INF;
        for(int i = 0; i < n; i++) {
            if(minD > max(dis1[i], dis2[i])) {
                res = i;
                minD = max(dis1[i], dis2[i]);
            }
        }
        return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  return 0;
}