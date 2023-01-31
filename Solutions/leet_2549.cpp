#include "bits/stdc++.h"

class Solution {
public:
    int distinctIntegers(int n) {
        unordered_set<int> s;
        int presize = 0;
        s.insert(n);
        while(s.size() != presize) {
          presize = s.size();
          FOR(i, 1, n) {
            for(auto x:s) {
              if(x % i == 1) {
                  // cout << x << endl;
                  s.insert(i);
              }
            }
          }
        }
        return s.size();
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}