#include "bits/stdc++.h"

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
      for(auto v : nums1) {
        auto it = lower_bound(nums2.begin(), nums2.end(), v);
        if(it != nums2.end() && *it == v) return v;
      }
      return -1;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}