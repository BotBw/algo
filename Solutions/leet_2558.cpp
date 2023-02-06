#include "bits/stdc++.h"

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
      priority_queue<int> q;
      for(auto v:gifts) q.push(v);
      while(k--) {
        auto tp = q.top(); q.pop();
        tp = sqrt(tp);
        q.push(tp);
      }
      ll res = 0;
      while(q.size()) {
        res += q.top();
        q.pop();
      }
      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}