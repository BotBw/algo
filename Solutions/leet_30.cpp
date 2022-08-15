#include "bits/stdc++.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {
        int n = s.size(), m = w.size();
        unordered_map<string, int> cnt;
        for(auto e:w) cnt[e]++;
        vector<int> res;
        int len = w[0].size();
        for(int i = 0; i + m * len <= n; i++) {
          int l = i, r = i + m * len;
          unordered_map<string, int> cur;
          for(int j = i; j < r; j += len) {
            cur[s.substr(j, len)]++;
          }
          if(cur == cnt) {
            res.push_back(i);
          }
        }
        return res;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}