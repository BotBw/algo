#include "bits/stdc++.h"

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& qs) {
        vector<vector<int>> mat(n + 1, vector<int>(n + 1));
        for(auto q:qs) {
          int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
          mat[x1][y1] += 1;
          mat[x1][y2 + 1] -= 1;
          mat[x2 + 1][y1] -= 1;
          mat[x2 + 1][y2 + 1] += 1;
        }
        vector<vector<int>> ret(n, vector<int>(n));
        ret[0][0] = mat[0][0];
        FOR(i, 1, n-1) {
          ret[i][0] = ret[i-1][0] + mat[i][0];
        }
        FOR(j, 1, n-1) {
          ret[0][j] = ret[0][j-1] + mat[0][j];
        }
        FOR(i, 1, n-1) {
          FOR(j, 1, n-1) {
            ret[i][j] = ret[i][j-1] + ret[i-1][j] - ret[i-1][j-1] + mat[i][j];
          }
        }
        return ret;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}