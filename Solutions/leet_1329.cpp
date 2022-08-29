#include "bits/stdc++.h"

class Solution {
public:
    void helper(vector<vector<int>>& mat, int x, int y) {
      int m = mat.size(), n = mat[0].size();
      vector<int> tmp;
      int i = x, j = y;
      while(i < m && j < n) {
        tmp.push_back(mat[i][j]);
        i++, j++;
      }
      sort(tmp.begin(), tmp.end());
      i = x, j = y;
      int k = 0;
      while(i < m && j < n) {
        mat[i][j] = tmp[k];
        i++, j++, k++;
      }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        FOR(i, 0, m-1) helper(mat, i, 0);
        FOR(j, 0, n-1) helper(mat, 0, j);
        return mat;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}