#include "bits/stdc++.h"

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        ll sum = 0;
        priority_queue<ll, vector<ll>, greater<ll>> q1, q2;
        FOR(i, 0, n-1) {
          if(nums[i] >= 0) {
            debug(nums[i]);
            sum += nums[i];
            q1.push(nums[i]);
          } else q1.push(-nums[i]);
        }
        while(q1.size() && (int)q2.size() <= k) {
          q2.push(q1.top());
          q1.pop();
        }
        vector<ll> cur;
        cur.push_back(sum);
        while(q2.size()) {
          ll dec = q2.top();
          q2.pop();
          vector<ll> next;
          int m = cur.size();
          int i = 0, j = 0;
          while(i < m && j < m && (int)next.size() <= k) {
            if(cur[i] >= cur[j] - dec) {
              next.push_back(cur[i++]);
            } else next.push_back(cur[j++] - dec);
          }
          while(i < m && (int)next.size() <= k) next.push_back(cur[i++]);
          while(j < m && (int)next.size() <= k) next.push_back(cur[j++] - dec);
          debug(dec, cur, next);
          swap(cur, next);
        }
        debug(cur);
        return cur[k-1];
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> a = {492634335,899178915,230945927};
  sort(a.begin(), a.end());
  Solution s;
  s.kSum(a, 2);
  return 0;
}