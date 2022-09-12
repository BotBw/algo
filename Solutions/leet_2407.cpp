#include "bits/stdc++.h"

class Solution {
public:
    static void push_up(int &p, const int &lc, const int& rc) {
      p = max(lc, rc);
    }
    static void push_down(int &p, int &lc, int ll, int &rc, int rl) {
      return;
    }
    static int ie() {return 0;}
    int lengthOfLIS(vector<int>& nums, int k) {
        segtree<int, push_up, push_down, ie> seg(0, 100005);
        int n = nums.size();
        vector<int> f(n);
        int res = 0;
        FOR(i, 0, n-1) {
          f[i] = 1;
          int maxf = 0;
          if(max(0, nums[i] - k) <= nums[i] - 1) maxf = seg.query(max(0, nums[i] - k), nums[i] - 1);
          f[i] = max(maxf + 1, 1);
          seg.update(nums[i], [&](int l, int r, int &x) { x = max(x, f[i]); });
          res = max(res, f[i]);
        }
        return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}