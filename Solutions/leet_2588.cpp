#include "bits/stdc++.h"

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
      unordered_map<int, int> hash;
      int n = nums.size();
      int sum = 0;
      ll ans = 0;
      hash[0]++;
      FOR(i, 0, n - 1) {
        sum ^= nums[i];
        ans += hash[sum ^ 0];
        hash[sum]++;
      }
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}