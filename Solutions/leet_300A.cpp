#include "bits/stdc++.h"

const int N = 2505;

class Solution {
public:
    static void push_up(int &a, const int& b, const int& c) {
      a = max(b, c);
    }
    static void push_down(int &a, int &b, int bl, int &c, int cl) {
      return;
    }
    static int ie() {
      return 0;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = nums, f(n);
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        auto find = [&](int ai) {
          return lower_bound(a.begin(), a.end(), ai) - a.begin();
        };
        segtree<int, push_up, push_down, ie> seg(0, a.size());
        int res = 0;
        FOR(i, 0, n-1) {
          int rnk = find(nums[i]);
          f[i] = 1;
          if(rnk > 0) f[i] = max(f[i], seg.query(0, rnk-1) + 1);
          seg.update(rnk, [&](int l, int r, int &x) { x = max(x, f[i]); });
          res = max(res, f[i]);
        }
        return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  return 0;
}