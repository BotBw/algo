#include "bits/stdc++.h"

class Solution {
public:
    int mod(int a, int b) {
      int res = a % b;
      if(res < 0) res += b;
      return res;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        FOR(i, 1, n) {
          pre[i] = pre[i-1] + nums[i-1];
        }

        vector<int> cnt(k);

        int ans = 0;

        FOR(i, 0, n) {
          int sum = mod(pre[i], k);
          ans += cnt[sum];
          cnt[sum]++;
        }
        return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}