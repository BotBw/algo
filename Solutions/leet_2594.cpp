#include "bits/stdc++.h"

class Solution {
public:
    ll _sqrt(ll n) {
      ll i = 0;
      while(i * i <= n) i++;
      i--;
      return i;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll maxR = 0;
        for(auto r: ranks) maxR = max(maxR, (ll)r);
        ll l = 0, r = 1ll * maxR * cars * cars;

        auto check = [&](ll time) {
          ll left = cars;
          for(auto r: ranks) {
            ll n = _sqrt(time / r);
            left -= n;
            if(left <= 0) return true;
          }
          return false;
        };

        while(l < r) {
          ll mi = (l + r) / 2;
          if(check(mi)) r = mi;
          else l = mi + 1;
        }
        return l;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}