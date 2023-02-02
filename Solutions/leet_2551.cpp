#include "bits/stdc++.h"

class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        int n = w.size();
        ll end = w.front() + w.back();
        FOR(i, 0, n-2) {
          w[i] += w[i + 1];
        }
        w.pop_back();
        sort(w.begin(), w.end());
        ll mx = end, mn = end;
        FOR(i, 0, k - 2) {
          mn += w[i];
        }
        FOR(i, n - k, n - 2) {
          mx += w[i];
        }
        cout << mx << "-" << mn << endl;
        return mx - mn;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}