#include "bits/stdc++.h"

class Solution {
public:
    int alternateDigitSum(int n) {
      string num = to_string(n);
      int res = 0;
      int mul = 1;
      FOR(i, 0, num.size() - 1) {
        res += mul * (num[i] - '0');
        mul *= -1;
      }
      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}