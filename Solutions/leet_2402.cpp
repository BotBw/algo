#include "bits/stdc++.h"

class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &me) {
        vector<ll> end(n);
        vector<int> cnt(n);
        sort(me.begin(), me.end());
        int m = me.size();
        FOR(i, 0, m-1) {
          int st = me[i][0], en = me[i][1];
          int min_id = 0;
          FOR(j, 0, n-1) {
            if(end[j] < end[min_id]) {
              min_id = j;
            }
            if(end[j] <= st) {
              end[j] = en;
              cnt[j]++;
              st = -1;
              break;
            }
          }
          if(st != -1) {
            end[min_id] += (en - st);
            cnt[min_id]++;
          }
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};

typedef vector<vector<int>> vvi;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  vvi a = {{0,10},{1,5},{2,7},{3,4}};
  cout << s.mostBooked(2 , a) << endl;
  return 0;
}