#include "bits/stdc++.h"
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        FOR(base, 2, n-2) {
          vector<int> di;
          int nn = n;
          while(nn) {
            di.push_back(nn % base);
            nn /= base;
          }
          bool ok = true;
          int l = 0, r = di.size() - 1;
          while(l < r) {
            if(di[l] != di[r]) {
              ok = false;
              break;
            }
            l++, r--;
          }
          if(!ok) return false;
        }
        return true;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}