#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mi = (l+r)/2;
            if(nums[mi] >= target) {
                r = mi;
            } else {
                l = mi + 1;
            }
        }
        if(l == nums.size()-1 && nums[l] < target) l++;
        return l;
    }
};