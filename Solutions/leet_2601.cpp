#include "bits/stdc++.h"

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
      int n = nums.size();
      auto isPrime = [](int x) {
        for(int i = 2; i * i <= x; i++) {
          if(x % i == 0) return false;
        }
        return true;
      };
      FOR(i, 0, n-1) {
        _FOR(j, nums[i] - 1, 2) {
          if(isPrime(j) && (i == 0 || nums[i] - j > nums[i - 1])) {
            nums[i] -= j;
            break;
          }
        }
        if(i != 0 && nums[i-1] >= nums[i]) return false;
      }
      return true;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}