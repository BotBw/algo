#include "bits/stdc++.h"

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
      int n = nums.size();
      nums.insert(nums.begin(), 0);
      sort(nums.begin() + 1, nums.end());

      vector<ll> pre(n + 1);
      FOR(i, 1, n) pre[i] = pre[i-1] + nums[i];

      vector<ll> ans;
      for(auto q:queries) {
        int i = upper_bound(nums.begin() + 1, nums.end(), q) - nums.begin();
        ll pree = 1ll * (i-1) * q - pre[i-1];
        ll post = pre[n] - pre[i-1] - 1ll * (n - i + 1) * q;
        ans.push_back(pree + post);
      }
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}