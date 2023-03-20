#include "bits/stdc++.h"

class Solution {
public:
    vector<int> evenOddBit(int n) {
      bitset<32> bi(n);
      int odd = 0, even = 0;
      FOR(i, 0, 31) {
        if(bi[i] == 1) {
          if(i % 2) odd++;
          else even++;
        }
      }
      return {even, odd};
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}