#include "bits/stdc++.h"

// 0 0 -> 0 0
// 0 1 -> 1 1
// 1 0 -> 1 1
// 1 1 -> 1 0

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
      bool has1 = false;
      for(auto c : s) if(c == '1') has1 = true;
      bool all0 = true;
      for(auto c : target) if(c != '0') all0 = false;
      if(has1) {
        return !all0;
      } else {
        return all0;
      }
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}