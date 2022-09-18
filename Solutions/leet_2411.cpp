#include "bits/stdc++.h"

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& a) {
        int n = a.size();
        vector<int> res(n);
        vector<int> pos(32, n);

        _FOR(i, n - 1, 0) {
          int cur = i;
          FOR(j, 0, 31) {
            if(a[i] >> j & 1) pos[j] = i;
            else if(pos[j] < n) cur = max(cur, pos[j]);
          }
          res[i] = cur - i + 1;
        }

        return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}