#include "bits/stdc++.h"

class Solution {
public:
    // f[i] = max(f[k] + score[i]) score[i] >= score[k]
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
      int n = scores.size();
      vector<pii> work(n + 1);
      FOR(i, 1, n) {
        work[i] = {ages[i - 1], scores[i - 1]};
      }
      sort(work.begin(), work.end());
      FOR(i, 1, n) {
          cout << work[i].first << "-" << work[i].second << endl;
      }
      vector<int> f(n + 1);
      int ans = -INT_INF;
      FOR(i, 1, n) {
        f[i] = work[i].second;
        FOR(k, 1, i - 1) {
          if(work[k].second <= work[i].second) {
            f[i] = max(f[i], f[k] + work[i].second);
          }
        }
        ans = max(ans, f[i]);
      }
      FOR(i, 1, n) cout << f[i] << " ";
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}