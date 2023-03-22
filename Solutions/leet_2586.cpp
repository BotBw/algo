#include "bits/stdc++.h"

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
      int ans = 0;
      FOR(i, left, right) {
        string s = words[i];
        char chs[] = {'a', 'e', 'i', 'o', 'u'};
        bool st = false, en = false;
        FOR(j, 0, 4) {
          if(s.front() == chs[j] ) {
            st = true;
          }
          if(s.back() == chs[j] ) {
            en = true;
          }
        }
        if(st && en) ans++;
      }
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}