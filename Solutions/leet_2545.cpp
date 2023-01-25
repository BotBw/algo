#include "bits/stdc++.h"

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
      sort(score.begin(), score.end(), [&](vector<int> &a, vector<int> &b) {
        return a[k] > b[k];
      });
      return score;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}