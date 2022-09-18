#include "bits/stdc++.h"


// cur  - c[1] + b[1] - c[2] + b[2] ..... >= c[i]
// cur >= c[1] - b[1] + c[2] - b[2] .... + c[i] 
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& t) {
      ll sum = 0;
      for(auto &p:t) sum += max(p[0] - p[1], 0);
      ll res = 0;
      for(auto &p:t) {
        ll cur = max(0, p[0] - p[1]);
        ll tmp = sum - cur;
        res = max(tmp + p[0], res);
      }
      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}