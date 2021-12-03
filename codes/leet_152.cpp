#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int posMax = nums[0], negMax = nums[0], maxv = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(posMax, negMax);
            }
            posMax = max(nums[i], posMax*nums[i]);
            negMax = min(nums[i], negMax*nums[i]);
            maxv = max(posMax, maxv);
        }
        return maxv;
    }
};