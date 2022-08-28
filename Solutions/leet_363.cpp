#include "bits/stdc++.h"

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size(), res = -INT_INF;
        auto pre = a;
        FOR(i, 1, m-1) {
          FOR(j, 0, n-1) {
            pre[i][j] += pre[i-1][j];
          }
        }
        FOR(lo, 0, m-1) {
          FOR(hi, lo, m-1) {
            set<int> hash;
            hash.insert(0);
            int cur = 0;
            FOR(j, 0, n-1) {
              int lo_s = lo > 0 ? pre[lo-1][j] : 0;
              int hi_s = pre[hi][j];
              cur += hi_s - lo_s;
              // pre + ans == cur
              // ans == cur - pre <= k
              //pre >= cur - k
              auto it = hash.lower_bound(cur - k);
              if(it != hash.end()) res = max(res, cur - *it);
              if(res == k) return k;
              hash.insert(cur);
            }
          }
        }
        return res;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}