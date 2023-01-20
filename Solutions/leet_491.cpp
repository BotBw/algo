#include "bits/stdc++.h"

class Solution {
public:

    bool check(vector<int> &a) {
      if(a.size() < 2) return false;
      FOR(i, 1, a.size() - 1) {
        if(a[i] < a[i-1]) return false;
      }
      return true;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> ans;
      for(int i = 0; i < (1 << n); i++) {
        vector<int> a;
        FOR(j, 0, nums.size() - 1) {
          if(i & (1 << j)) {
            a.push_back(nums[j]);
          }
        }
        if(check(a)) ans.push_back(a);
      }
      sort(ans.begin(), ans.end());
      ans.erase(unique(ans.begin(), ans.end()), ans.end());
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}