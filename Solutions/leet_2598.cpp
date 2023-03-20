#include "bits/stdc++.h"

class Solution {
public:
  int mod(int a, int b) {
    int c = a % b;
    if(c < 0) c += b;
    return c;
  }

  int findSmallestInteger(vector<int>& nums, int value) {
    vector<int> last(value, -1);
    vector<bool> good(nums.size() + 1);
    for(auto v:nums) {
      int m = mod(v, value);
      if(last[m] != -1) {
        last[m] += value;
        if(last[m] <= nums.size()) good[last[m]] = true;
      } else {
        last[m] = m;
        if(last[m] <= nums.size()) good[last[m]] = true;
      }
    }
    FOR(i, 0, nums.size()) {
      if(!good[i]) return i;
    }
    return value;
  }
};



signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  vector<int> nums = {53,11,64,66,18,61,131,26,100,88,63,113,129,135,137,35,79,101,10,56,41,3,43,88,133,127,91,49,134,63,70,14,2,36,9,48,29,23,53,25,17,26,44,20,8,17,85,132,85,23,96,12,38,105,99,135,76,40,29,20,138,29,46,82,88,60,55,138,125,82,78,0,87,77,50,31,71,117,96,12,28,11,42,55,32,40,47,98,91,46,109,40,26,108,111,67,110,49,38,36};
  s.findSmallestInteger(nums, 140);
  return 0;
}