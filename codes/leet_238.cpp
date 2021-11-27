#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), ans(n);
        pre[0] = nums[0];
        FOR(i, 1, n-1) pre[i] = pre[i-1]*nums[i];
        #ifdef DEBUG
        FOR(i, 1, n-1) cout << pre[i] <<' ';
        #endif
        ans[n-1] = nums[n-1];
        int suf = nums[n-1];
        _FOR(i, n-2, 1) ans[i] = suf*pre[i-1], suf *= nums[i];
        #ifdef DEBUG
        // FOR(i, 1, n-1) cout << ans[i] <<' ';
        #endif
        return ans;
    }
};