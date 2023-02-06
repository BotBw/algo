#include "bits/stdc++.h"

class Solution {
public:
    long long minCost(vector<int> a1, vector<int> a2) {
        unordered_map<int, int> cnt;
        for(auto v:a1) cnt[v]++;
        for(auto v:a2) cnt[v]++;
        for(auto p:cnt) {
          if(p.second % 2) return -1;
        }
        unordered_map<int, int> cnt1, cnt2;
        for(auto v:a1) cnt1[v]++;
        for(auto v:a2) cnt2[v]++;
        vector<int> w1, w2;
        for(auto p:cnt) {
          int val = p.first, c = p.second;
          int c1 = cnt1.count(val) ? cnt1[val] : 0;
          int c2 = cnt2.count(val) ? cnt2[val] : 0;
          FOR(k, c/2, c1-1) w1.push_back(val);
          FOR(k, c/2, c2-1) w2.push_back(val);
        }
        int mn = INT_INF;
        int n = a1.size();
        FOR(i, 0, n - 1) mn = min(a1[i], mn);
        FOR(i, 0, n - 1) mn = min(a2[i], mn);
        
        ll res = 0;

        sort(w1.begin(), w1.end());
        sort(w2.rbegin(), w2.rend());
        
        FOR(i, 0, w1.size() - 1) {
          res += min({w1[i], w2[i], mn * 2});
        }
        return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  cout << s.minCost({4,2,2,2}, {1,4,1,2}) << endl;
  return 0;
}