#include "bits/stdc++.h"

class Solution {
public:
    
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n + 1);
        FOR(i, 1, n) {
          vector<int> cnt(n);
          int mn = INT_INF;
          int cost = 0;
          _FOR(j, i, 1) {
            int x = nums[j-1];
            if(cnt[x] == 1) cost += 2;
            else if(cnt[x] >= 2) cost += 1;
            cnt[x]++;
            mn = min(mn, f[j-1] + cost);
          }
          f[i] = mn + k;
        }
        return f[n];
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}