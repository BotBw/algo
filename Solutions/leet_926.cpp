#include "bits/stdc++.h"

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> pre(n + 2);
        FOR(i, 1, n) {
          pre[i] = pre[i-1] + (s[i-1] == '1');
        }
        pre[n + 1] = pre[n];
        int ans = INT_INF;
        FOR(i, 1, n + 1) {
          ans = min(pre[i-1] + (n - i + 1 - pre[n] + pre[i-1]), ans);
        }
        return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}