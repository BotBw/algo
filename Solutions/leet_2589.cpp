#include "bits/stdc++.h"


class Solution {
public:
  int findMinimumTime(vector<vector<int>>& tasks) {
    int ans = 0;
    sort(tasks.begin(), tasks.end(), [&](const vector<int> &t1, const vector<int> &t2) {
      return t1[1] < t2[1];
    });
    int n = tasks.size();
    vector<bool> run(2005);
    for(const auto &t: tasks) {
      int st = t[0], en = t[1], dur = t[2];
      FOR(j, st, en) {
        if(run[j]) dur--;
      }
      _FOR(j, en, st) {
        if(dur <= 0) break;
        if(run[j]) continue;
        dur--;
        run[j] = true;
        ans++;
      }
    }
    return ans;
  }
};



;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}