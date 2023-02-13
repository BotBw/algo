#include "bits/stdc++.h"

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
      int n = nums.size();
      int l = 0 ,r = n - 1;
      ll res = 0;
      while(l < r) {
        string num = to_string(nums[l]) + to_string(nums[r]);
        stringstream sstream(num);
        ll inc = 0;
        sstream >> inc;
        res += inc;
        l++; r--;
      }
      if(l <= r) res += nums[l];
      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}