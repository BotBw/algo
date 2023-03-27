#include "bits/stdc++.h"

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
      int res = 0;
      res += min(k, numOnes);
      k -= min(k, numOnes);
      if(k == 0) return res;

      k -= min(k, numZeros);
      if(k == 0) return res;

      res -= min(k, numNegOnes);
      return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}