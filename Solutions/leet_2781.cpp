#include "bits/stdc++.h"

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forb) {
      int n = word.size();
      unordered_set<string> hash;
      for(auto &s: forb) hash.insert(s);
      int l = 0;
      int ans = 0;
      FOR(r, 0, n-1) {
        _FOR(i, r, max(l, r - 9)) {
          if(hash.count(word.substr(i, r - i + 1))) {
            l = i + 1;
            break;
          }
        }
        ans = max(ans, r - l + 1);
      }
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}