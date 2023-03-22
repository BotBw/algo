#include "bits/stdc++.h"

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
      multiset<int> se;
      for(auto v:nums) se.insert(v);
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int ans = 0;
      _FOR(i, n - 1, 0) {
        int v = nums[i];
        auto it = se.lower_bound(v + 1);
        if(it != se.end()) {
          ans++;
          se.erase(it);
        }
      }
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}