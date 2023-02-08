#include "bits/stdc++.h"

class Solution {
public:
    int maximizeWin(vector<int>& pos, int k) {
        int n = pos.size();
        vector<vector<int>> f(n + 1, vector<int>(2));
        int ans = 0;
        FOR(i, 1, n) {
          int j = lower_bound(pos.begin(), pos.end(), pos[i-1] - k) - pos.begin();
          if(pos[i-1] - pos[j] > k) j++;
          j++;
          f[i][0] = max(f[i-1][0], i - j + 1);
          f[i][1] = max(f[i-1][1], f[j - 1][0] + i - j + 1);
          ans = max(ans, f[i][1]);
        }
        return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  vector<int> t1 = {1,1,2,2,3,3,5};
  cout << s.maximizeWin(t1, 2) << endl;
  return 0;
}