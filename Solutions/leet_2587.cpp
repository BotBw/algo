#include "bits/stdc++.h"

class Solution {
public:
    int maxScore(vector<int>& nums) {
      sort(nums.begin(), nums.end(), greater<int>());
      ll sum = 0, ans = 0;
      for(auto v: nums) {
        sum += v;
        if(sum > 0) ans++;
      }
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}