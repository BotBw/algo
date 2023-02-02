#include "bits/stdc++.h"

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
      int n = nums.size();
      vector<vector<ll>> pre(n, vector<ll>(n + 1)), post(n, vector<ll>(n + 1));

      FOR(x, 1, n) if(x > nums[0]) pre[0][x]++;
      FOR(i, 1, n-1) {
        FOR(x, 1, n) {
          pre[i][x] = pre[i - 1][x];
          if(x > nums[i]) pre[i][x]++;
        }
      }

      FOR(x, 1, n) if(x < nums[n-1]) post[n-1][x]++;
      _FOR(j, n - 2, 0) {
        FOR(x, 1, n) {
          post[j][x] = post[j + 1][x];
          if(nums[j] > x) post[j][x]++;
        }
      }
      ll res = 0;
      FOR(j, 0, n-1) {
        FOR(k, j + 1, n - 1) {
          if(nums[k] < nums[j]) {
            res += pre[j][nums[k]] * post[k][nums[j]];
          }
        }
      }
      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}