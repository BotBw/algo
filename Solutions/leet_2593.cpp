#include "bits/stdc++.h"

class Solution {
public:
    long long findScore(vector<int>& nums) {
      int n = nums.size();
      set<pii> se;
      vector<bool> marked(n);
      FOR(i, 0, n-1) {
        se.insert({nums[i], i});
      }
      ll res = 0;
      for(auto p:se) {
        int val = p.first, id = p.second;
        if(!marked[id]) {
          marked[id] = true;
          if(id > 0) marked[id - 1] = true;
          if(id < n - 1) marked[id + 1] = true;
          res += val;
        }
      }
      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}