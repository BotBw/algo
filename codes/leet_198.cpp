#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 0) return 0;
        else if(nums.size() <= 1) return nums[0];
        else if(nums.size() <= 2) return max(nums[1], nums[0]);
        vector<int> opt(nums.size(), -1);
        opt[0] = nums[0];
        opt[1] = max(nums[0], nums[1]);
        for(int i = 2; i < opt.size(); i++){
            opt[i] = max(opt[i - 1], opt[i - 2] + nums[i]);
        }
        return opt.back();
    }
};