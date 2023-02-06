#include "bits/stdc++.h"

class Solution {
public:
    bool check(char c) {
      static char tmp[] = {'a', 'e', 'i', 'o', 'u'};
      FOR(i, 0, 4) {
        if(c == tmp[i]) return true;
      }
      return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
      int n = words.size();
      vector<int> pre(n + 1);
      FOR(i, 1, n) {
        if(check(words[i-1].front()) && check(words[i-1].back())) pre[i]++;
        pre[i] += pre[i-1];
      }
      vector<int> ret;
      for(auto q:queries) {
        ret.push_back(pre[q[1] + 1] - pre[q[0]]);
      }
      return ret;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}