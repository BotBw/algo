#include "bits/stdc++.h"

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trusting(n + 1, 0);
    vector<int> trusted(n + 1, 0);

    for (int i = 0; i < trust.size(); i++) {
      trusting[trust[i][0]]++;
      trusted[trust[i][1]]++;
    }

    int ans = -1;

    FOR(i, 1, n) {
      if (trusting[i] == 0 && trusted[i] == n - 1) ans = i;
    }

    return ans;
  }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}