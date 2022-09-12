#include "bits/stdc++.h"

class Solution {
public:
    int minGroups(vector<vector<int>>& itvl) {
        sort(itvl.begin(), itvl.end());
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto &p:itvl) {
          int st = p[0], en = p[1];
          if(q.size()) {
            auto lst = q.top();
            if(lst >= st) {
              q.push(en);
            } else {
              q.pop();
              q.push(en);
            }
          } else q.push(en);
        }
        return q.size();
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  return 0;
}