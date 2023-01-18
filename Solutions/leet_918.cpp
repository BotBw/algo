#include "bits/stdc++.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int n = nums.size();
      int max1 = nums[0], min1 = nums[0], sum = nums[0];
      int cur1 = nums[0], cur2 = nums[0];
      FOR(i, 1, n-1) {
        cur1 = max(cur1 + nums[i], nums[i]);
        cur2 = min(cur2 + nums[i], nums[i]);
        sum += nums[i];
        max1 = max(cur1, max1);
        min1 = min(min1, cur2);
      }

      if(sum == min1) return max1;
      return max(max1, sum - min1);
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  vector<int> a = {-3, -2, -3};
  cout << s.maxSubarraySumCircular(a) << endl;
  return 0;
}