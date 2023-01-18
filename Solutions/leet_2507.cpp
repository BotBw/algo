#include "bits/stdc++.h"

class Solution {
public:
    int smallestValue(int n) {
        while(true) {
          int pren = n;
          int nn = 0;
          for(int i = 2; i < n; i++) {
            while(n % i == 0) {
              n /= i;
              nn += i;
            }
          }
          if(n != 1) nn += n;
          n = nn;
          if(nn == pren) break;
        }
        return n;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  cout << s.smallestValue(4) << endl;
  return 0;
}