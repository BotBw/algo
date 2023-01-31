#include "bits/stdc++.h"

class Solution {
public:
    static const int MOD = 1e9 + 7;
    ll pow2(int a) {
      if(a == 0) return 1;
      ll ret = pow2(a/2) % MOD;
      if(a % 2) {
        return (2 * ret * ret) % MOD;
      } else {
        return (ret * ret) % MOD;
      }
    }
    int monkeyMove(int n) {
        return (pow2(n) - 2 + MOD) % MOD;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}