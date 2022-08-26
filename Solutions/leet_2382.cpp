#include "bits/stdc++.h"

class Solution {
public:
    struct tag {
      ll sum;
      ll maxSum;
      ll leftMaxSum;
      ll rightMaxSum;
      bool allCover;
    };
    static void push_up(tag &f, const tag& a, const tag& b) {
      f.maxSum = max({a.rightMaxSum + b.leftMaxSum, a.maxSum, b.maxSum});
      f.sum = a.sum + b.sum;
      if(a.allCover) f.leftMaxSum = a.sum + b.leftMaxSum;
      else f.leftMaxSum = a.leftMaxSum;
      if(b.allCover) f.rightMaxSum = b.sum + a.rightMaxSum;
      else f.rightMaxSum = b.rightMaxSum;
      f.allCover = a.allCover && b.allCover;
    }
    static void push_down(tag &a, tag &b, int lenb, tag &c, int lenc) {

    }
    static tag ie() {
      return {0, 0, 0, 0, true};
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
      int n = nums.size();
      vector<tag> init(n);
      FOR(i, 0, n-1) {
        init[i] = {nums[i], nums[i], nums[i], nums[i], true};
      }
      segtree<tag, push_up, push_down, ie> s(0, n-1, init);
      vector<ll> res;
      for(auto q:removeQueries) {
        s.update(q, [](int len, tag &x) {x = {0, 0, 0, 0, false}; });
        res.push_back(s.query(0, n-1).maxSum);
      }
      return res;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> nums = {1,2,5,6,1}, removeQueries = {0,3,2,4,1};
  Solution s;
  debug(s.maximumSegmentSum(nums, removeQueries));
  return 0;
}