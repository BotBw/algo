#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // const int maxL = 1e5+5;
        int ans = nums[0];
        // int f[maxL];
        // f[0] = nums[0];
        int f = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(f >= 0) {
                f += nums[i];
            } else {
                f = nums[i];
            }
            ans = max(f, ans);
        }
        return ans;
    }
};