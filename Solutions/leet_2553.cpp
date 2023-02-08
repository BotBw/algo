#include "bits/stdc++.h"

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
      vector<int> res;
      for(auto v:nums) {
        string s = to_string(v);
        for(auto c:s) {
          res.push_back(c - '0');
        }
      }
      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}