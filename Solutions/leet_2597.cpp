#include "bits/stdc++.h"

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
      unordered_map<int, int> cnt;
      int ans = 0;
      dfs(k, nums, 0, cnt, ans);
      return ans;
    }

    void dfs(int k, vector<int> &nums, int i, unordered_map<int, int>& cnt, int &ans) {
      if(i == nums.size()) {
        if(cnt.size()) {
          bool nonZero = false;
          for(auto p:cnt) {
            if(p.second) {
              nonZero = true;
              break;
            }
          }
          if(nonZero) ans++;
        }
        return;
      }
      dfs(k, nums, i + 1, cnt, ans);
      if(cnt[nums[i] + k] == 0 && cnt[nums[i] - k] == 0) {
        cnt[nums[i]]++;
        dfs(k, nums, i + 1, cnt, ans);
        cnt[nums[i]]--;
      }
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  vector<int> a = {2,4,6};
  s.beautifulSubsets(a, 2);
  return 0;
}