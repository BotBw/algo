#include "bits/stdc++.h"

class Solution {
public:
    int maxCount(vector<int>& a, int n, int maxSum) {
      unordered_set<int> hash;
      for(auto v:a) hash.insert(v);
      int cur = 0, cnt = 0;
      FOR(i, 1, n) {
        if(hash.count(i)) continue;
        if(cur + i <= maxSum) cur += i, cnt++;
        else break;
      }
      return cnt;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}