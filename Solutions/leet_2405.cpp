#include "bits/stdc++.h"

class Solution {
public:
    int partitionString(string s) {
      int res = 0;
      set<char> hash;
      for(auto c:s) {
        if(hash.count(c)) {
          hash.clear();
          res++;
        }
        hash.insert(c);
      }
      return res + !hash.empty();
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}