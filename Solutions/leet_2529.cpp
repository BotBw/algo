#include "bits/stdc++.h"

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(auto e: nums) {
          if(e > 0) pos++;
          else if(e < 0) neg++;
        }
        return max(pos, neg);
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}