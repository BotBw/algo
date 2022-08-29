#include "bits/stdc++.h"

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        modint::setmod(1e9 + 7);
        modint res(1);
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto v:nums) q.push(v);
        while(k--) {
          auto x = q.top();
          q.pop();
          x++;
          q.push(x);
        }
        while(q.size()) {
          auto x = q.top();
          q.pop();
          res *= x;
        }
        return res.getval();
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}