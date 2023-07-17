#include "bits/stdc++.h"

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
      int n = nums.size();
      map<int, unordered_set<int>> l, r;
      unordered_map<int, int> l_cnt, r_cnt;
      FOR(i, 0, n-1) {
        r_cnt[nums[i]]++;
      }
      for(auto p: r_cnt) {
        r[p.second].insert(p.first);
      }
      FOR(i, 0, n-1) {
        int val = nums[i];
        l[l_cnt[val]].erase(val);
        if(l[l_cnt[val]].size() == 0) l.erase(l_cnt[val]);
        l_cnt[val]++;
        l[l_cnt[val]].insert(val);

        r[r_cnt[val]].erase(val);
        if(r[r_cnt[val]].size() == 0) r.erase(r_cnt[val]);
        r_cnt[val]--;
        if(r_cnt[val] == 0) r_cnt.erase(val);
        else r[r_cnt[val]].insert(val);

        if(i == 2) debug(l.rbegin()->first, r.rbegin()->first);
        if(l.empty() || r.empty()) continue;
        if(l.rbegin()->first * 2 <= i + 1) continue;
        if(r.rbegin()->first * 2 <= (n - i - 1)) continue;
        if(*l.rbegin()->second.begin() == *r.rbegin()->second.begin()) return i;
      }
      return -1;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> in1 = {1,2,2,2};
  Solution s;
  cout << s.minimumIndex(in1);
  return 0;
}