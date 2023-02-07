#include "bits/stdc++.h"

class Solution {
public:
    int totalFruit(vector<int>& a) {
      int n = a.size();
      int l = 0, r = n;
      auto check = [&](int mi) {
        unordered_map<int, int> cnt;
        FOR(i, 0, mi-2) {
          cnt[a[i]]++;
        }
        int l = 0;
        FOR(r, mi - 1, n - 1) {
          cnt[a[r]]++;
          if(r - l + 1 > mi) {
            cnt[a[l]]--;
            if(cnt[a[l]] == 0) cnt.erase(a[l]);
            l++;
          }
          if(cnt.size() <= 2) return true;
        }        
        return false;
      };
      while(l < r) {
        int mi = (l + r + 1) / 2;
        if(check(mi)) l = mi;
        else r = mi - 1;
      }
      return l;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}