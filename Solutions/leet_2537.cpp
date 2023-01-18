#include "bits/stdc++.h"

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
      unordered_map<int, int> cnt;
      int n = nums.size();
      ll res = 0;
      int l = 0, cur = 0;
      FOR(r, 0, n-1) {
        int e = nums[r];
        cur += cnt[e];
        cnt[e]++;
        while(l <= r && cur - (cnt[nums[l]] - 1) >= k) {
          cur -= cnt[nums[l]] - 1;
          cnt[nums[l]]--;
          l++;
        }
        if(cur >= k) {
          debug(l, r, cur);
          res += l + 1;
        }
      }

      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;

  vector<int> t1 = {1,1,1,1,1}, t2 = {3,1,4,3,2,2,4}, t3 = {2,3,1,3,2,3,3,3,1,1,3,2,2,2};
  // cout << s.countGood(t1, 10) << endl;
  // cout << s.countGood(t2, 2) << endl;
  cout << s.countGood(t3, 18) << endl;
  return 0;
}