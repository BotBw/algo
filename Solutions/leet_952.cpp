#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG
const int maxV = 1e5+5;

class Solution {
public:
    int f[maxV];
    int sz[maxV];
    int largestComponentSize(vector<int>& nums) {
      init();
      int ans = 0;
      unordered_map<int, int> mp;                            // maintains {parent of component: frequency}
        for(auto c : nums) 
            for(int f = 2; f <= sqrt(c); f++)                  // finding factors of each element
                if(c % f == 0)                                 // if f divides c, then f & c/f are its factor. So union them
                    merge(c, f), 
                    merge(c, c/f);
      FOR(i, 0, nums.size()-1) ans = max(ans, ++mp[find(nums[i])]);
      return ans;
    }
    void init() {
      for(int i = 0; i < maxV; i++) f[i] = i, sz[i] = 1;
    }
    int find(int x) {
      if(f[x] == x) return x;
      return f[x] = find(f[x]);
    }
    void merge(int x, int y) {
      int fx = find(x), fy = find(y);
      if(fx == fy) return;
      if(sz[fy] > sz[fx]) swap(fx, fy);
      f[fy] = f[fx];
      sz[fx] += sz[fy];
    }
};