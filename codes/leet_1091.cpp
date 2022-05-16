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
    typedef pair<int,int> PII;

    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        if(g[0][0] == 1) return -1; 
        static int dx[] = {-1, -1, -1, 0, 1, 1 ,1, 0};
        static int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        vector<vector<int>> dis(g.size(), vector<int>(g.size(), -1));
        vector<vector<bool>> vis(g.size(), vector<bool>(g.size()));
        queue<PII> q;
        q.push({0, 0});
        vis[0][0] = 1;
        dis[0][0] = 1;
        while(!q.empty()) {
            auto frt = q.front();
            q.pop();
            int x = frt.first, y = frt.second;
            for(int i = 0; i < 8; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if(xx < 0 || xx >= g.size() || yy < 0 || yy >= g.size()) continue;
                if(g[xx][yy] == 1) continue;
                if(xx == g.size()-1 && yy == g.size() -1) return dis[x][y] + 1;
                if(vis[xx][yy]) continue;
                vis[xx][yy] = 1;
                dis[xx][yy] = dis[x][y] + 1;
                q.push({xx, yy});
            }
        }
        return dis[g.size()-1][g.size()-1];
    }
};
#else
int main() {
  return 0;
}
#endif