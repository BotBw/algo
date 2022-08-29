#include "bits/stdc++.h"

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<bool>> graph(k + 1, vector<bool>(k+1));
        vector<int> ind(k + 1);
        for(auto p:rowConditions) {
          if(graph[p[0]][p[1]]) continue;
          graph[p[0]][p[1]] = true;
          ind[p[1]]++;
        }
        queue<int> q;
        vector<int> row;
        FOR(i, 1, k) if(ind[i] == 0) q.push(i);
        debug(ind);
        while(q.size()) {
          int u = q.front();
          row.push_back(u);
          q.pop();
          FOR(v, 1, k) {
            if(graph[u][v]) {
              ind[v]--;
              if(ind[v] == 0) q.push(v);
            }
          }
        }
        debug(ind);
        debug(row.size(), k);
        if(row.size() != k) return {};
        graph = vector<vector<bool>>(k + 1, vector<bool>(k+1));
        ind = vector<int>(k + 1);
        for(auto p:colConditions) {
          if(graph[p[0]][p[1]]) continue;
          graph[p[0]][p[1]] = true;
          ind[p[1]]++;
        }
        vector<int> col;
        FOR(i, 1, k) if(ind[i] == 0) q.push(i);
        while(q.size()) {
          int u = q.front();
          col.push_back(u);
          q.pop();
          FOR(v, 1, k) {
            if(graph[u][v]) {
              ind[v]--;
              if(ind[v] == 0) q.push(v);
            }
          }
        }
        if(col.size() != k) return {};
        vector<int> rowid(k + 1), colid(k + 1);
        FOR(i, 0, k-1) rowid[row[i]] = i;
        FOR(i, 0, k-1) colid[col[i]] = i;
        vector<vector<int>> res(k, vector<int>(k));
        FOR(i, 1, k) res[rowid[i]][colid[i]] = i;
        return res;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int k =8;
  vector<vector<int>> a = {{1,2},{7,3},{4,3},{5,8},{7,8},{8,2},{5,8},{3,2},{1,3},{7,6},{4,3},{7,4},{4,8},{7,3},{7,5}}

, b = {{5,7},{2,7},{4,3},{6,7},{4,3},{2,3},{6,2}}
;
  
  Solution s;
  s.buildMatrix(k, a, b);
  return 0;
}