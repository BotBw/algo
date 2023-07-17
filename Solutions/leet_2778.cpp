#include "bits/stdc++.h"

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
      int n = nums.size();
      nums.insert(nums.begin(), 0);
      int sum = 0;
      FOR(i, 1, n) {
        if(n % i == 0) {
          sum += nums[i] * nums[i];
        }
      }
      return sum;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}