#include "bits/stdc++.h"

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, less<int>> q;
      for(auto e:nums) q.push(e);
      ll res = 0;
      FOR(i, 1, k) {
        res += q.top();
        int a = q.top();
        q.pop();
        a = (a + 2) / 3;
        q.push(a);
      } 
      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}