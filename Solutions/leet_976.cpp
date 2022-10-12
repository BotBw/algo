#include "bits/stdc++.h"

class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        _FOR(i, n-1, 2) {
          if(a[i] < a[i-1] + a[i-2]) return a[i] + a[i-1] + a[i-2];
        }
        return 0;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}