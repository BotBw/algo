#include "bits/stdc++.h"

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
      int n = nums1.size();
      if(k == 1) {
        ll ans = 0;
        FOR(i, 0, n-1) {
          ans = max(ans, (ll)nums1[i] * nums2[i]);
        }
        return ans;
      }
      vector<pii> cp(n);
      FOR(i, 0, n-1) {
        cp[i] = {nums2[i], nums1[i]};
      }
      sort(cp.begin(), cp.end());
      ll ans = 0, maxsum = 0;
      priority_queue<int, vector<int>, greater<int>> pq;
      _FOR(i, n-1, 0) {
        if(int(pq.size()) == k - 1) {
          ans = max(ans, cp[i].first * (cp[i].second + maxsum));
          if(cp[i].second > pq.top()) {
            maxsum += (cp[i].second - pq.top());
            pq.pop();
            pq.push(cp[i].second);
          }
        } else {
          pq.push(cp[i].second);
          maxsum += cp[i].second;
        }
      }
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> t11 = {1,3,3,2}, t12 = {2,1,3,4};
  Solution s;
  cout << s.maxScore(t11, t12, 3);
  priority_queue<int, vector<int>, greater<int>> q;
  FOR(i, 1, 10) q.push(i);
  while(q.size()) {
    cout << q.top() << endl;
    q.pop();
  }
  return 0;
}