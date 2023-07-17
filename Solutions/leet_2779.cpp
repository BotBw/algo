#include "bits/stdc++.h"

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int ans = 0;
      FOR(l, 0, n-1) {
        int r = lower_bound(nums.begin() + l, nums.end(), nums[l] + k * 2 + 1) - nums.begin() - 1;
        ans = max(ans, r - l + 1);
      }
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}