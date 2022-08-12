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
    bool check(const vector<int>& nums, int i) {
      if(i % 2)
        return nums[i] == nums[i+1];
      else
        return nums[i] != nums[i+1];
    }
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
          int mi = (l+r)/2;
          if(check(nums, mi)) {
            r = mi;
          } else {
            l = mi + 1;
          }
        }
        return (l%2) ? nums[l-1] : nums[l];
    }
};