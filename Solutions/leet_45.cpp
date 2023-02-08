#include "bits/stdc++.h"

class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
      vector<int> f(n + 1, INT_INF);
      f[n] = 0;
      _FOR(i, n, 1) {
        FOR(j, 0, nums[i - 1]) {
          f[i] = min(f[i], f[min(n, i + j)] + 1);
        }
      }
      return f[1];
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}