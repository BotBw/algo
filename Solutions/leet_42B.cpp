#include "bits/stdc++.h"

class Solution {
public:
    int trap(vector<int>& h) {
        stack<int> s;
        int n = h.size();
        int res = 0;
        FOR(i, 0, n-1) {
          while(s.size() && h[i] >= h[s.top()]) {
            int r = i, mi = s.top();
            s.pop();
            if(s.empty()) continue;
            int l = s.top();
            res += (r - l - 1) * (min(h[l], h[r]) - h[mi]);
          }
          s.push(i);
        }
        return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}