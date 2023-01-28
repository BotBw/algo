#include "bits/stdc++.h"

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
      if(k == 0) return nums1 == nums2 ? 0 : -1;
      ll neg = 0, pos = 0;
      int n = nums1.size();
      FOR(i, 0, n-1) {
        if((nums1[i] - nums2[i]) % k != 0) return -1;
        if(nums1[i] > nums2[i]) pos += nums1[i] - nums2[i];
        else if(nums2[i] > nums1[i]) neg += nums2[i] - nums1[i];
      }
      if(pos != neg) return -1;
      return pos / k;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}