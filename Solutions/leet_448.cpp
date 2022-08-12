#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _for(i, a, b) for(int i = (a); i >= (b); --i)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans(0);
        int n = nums.size()-1;
        for(i, 0, n) {
          int id;
          id = (nums[i] > 0) ? (nums[i] - 1) : (-nums[i] - 1);
          nums[id] = (nums[id] < 0) ? nums[id] : (-nums[id]);
        }
        for(i, 0, n) {
          if(nums[i] > 0)
            nums.push_back(i+1);
        }
        return ans;
    }
};