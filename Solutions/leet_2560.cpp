#include "bits/stdc++.h"

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
      int n = nums.size();
      int l = 1, r = 1e9;
      auto check = [&](int mi) {
        vector<int> f(n + 2);
        FOR(i, 2, n + 1) {
          int v = nums[i - 2];
          if(v <= mi) {
            f[i] = max(f[i - 1], f[i - 2] + 1);
          } else {
            f[i] = f[i - 1]; 
          }
        }
        return f[n + 1] >= k;
      };
      while(l < r) {
        int mi = (l + r) / 2;
        if(check(mi)) r = mi;
        else l = mi + 1;
      }
      return l;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}