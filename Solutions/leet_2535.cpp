#include "bits/stdc++.h"

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1 = accumulate(nums.begin(), nums.end(), 0);

        int sum2 = 0;
        for(auto e : nums) {
          string str = to_string(e);
          for(auto c : str) {
            sum2 += c - '0';
          }
        }
        return abs(sum1 - sum2);
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}