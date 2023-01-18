#include "bits/stdc++.h"

class Solution {
public:
    bool isSimilar(string &a, string &b) {
      unordered_set<char> aa, bb;
      for(auto c:a) aa.insert(c);
      for(auto c:b) bb.insert(c);
      if(aa.size() != bb.size()) return false;
      for(auto p:aa) {
        if(bb.count(p) == 0) return false;
      }
      return true;
    }
    int similarPairs(vector<string>& words) {
        int n =words.size();
        int ans = 0;
        FOR(i, 0, n - 1) {
          FOR(j, i + 1, n - 1) {
            if(isSimilar(words[i], words[j])) ans++;
          }
        }
        return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}