#include "bits/stdc++.h"

class Solution {
public:
    int trap(vector<int>& h) {
        stack<int> s;
        int n = h.size();
        h.insert(h.begin(), 0);
        h.push_back(0);
        vector<int> pre(n + 1);
        FOR(i, 1, n) pre[i] = pre[i-1] + h[i];
        int res = 0;
        s.push(0);
        int cur = 0;
        FOR(i, 1, n) {
          while(s.size() && h[i] >= h[s.top()]) {
            if(s.top() == cur) {
              res += h[cur] * (i - 1 - cur) - (pre[i - 1] - pre[cur]);
              cur = i;
            }
            s.pop();
          }
          s.push(i);
        }
        s = stack<int>();
        s.push(n + 1);
        cur = n + 1;
        _FOR(i, n, 1) {
          while(s.size() && h[i] >= h[s.top()]) {
            if(s.top() == cur) {
              res += h[cur] * (cur - 1 - i) - (pre[cur-1] - pre[i]);
              cur = i;
            }
            s.pop();
          }
          s.push(i);
        }
        return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << endl << s.trap(h);
  return 0;
}