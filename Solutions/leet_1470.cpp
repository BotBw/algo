#include "bits/stdc++.h"

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
      vector<int> ret(n * 2);
      int i = 0, j = n;
      FOR(k, 0, 2 * n - 1) {
        if(k % 2) {
          ret[k] = nums[j++];
        } else {
          ret[k] = nums[i++];
        }
      }
      return ret;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}