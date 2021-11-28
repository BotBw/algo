#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG
class Solution {
public:
    vector<int> vis;
    int n;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vis = vector<int>(n, 0);
        vector<int> cur;
        vector<vector<int>> ans;
        cur.push_back(0);
        vis[0] = 1;
        dfs(0,cur,ans,graph);
        return ans;
    }
    
    void dfs(int u, vector<int> &cur, vector<vector<int>> &ans,vector<vector<int>>& graph) {
        // cout << endl << u << ":";
        if(n-1 == u) ans.push_back(cur);
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            // cout << vis[v] << ' ';
            if(vis[v]) continue;
            vis[v] = 1;
            cur.push_back(v);
            dfs(v,cur,ans,graph);
            vis[v] = 0;
            cur.pop_back();
        }
    }
};