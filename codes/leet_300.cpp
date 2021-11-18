#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      if(nums.empty()) return 0;
      int n = nums.size();
      vector<int> dp;
      dp.push_back(nums[0]);
      FOR(i, 0, n-1) {
        if(nums[i] > dp.back()) {
          dp.push_back(nums[i]);
        } else {
          *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        }
      }
      return dp.size();       
    }
};