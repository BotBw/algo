#include "bits/stdc++.h"

class Solution {
public:
    struct tmp {
      int cost, back;
      bool operator<(const tmp &o) const {
        ll a = max(cost, o.cost + cost - back), b = max(o.cost, o.cost + cost - o.back);
        if(a == b) return cost > o.cost;
        return a > b;
      }
    };
    long long minimumMoney(vector<vector<int>>& tran) {
        int n = tran.size();
        ll l = 0, r = 0;
        vector<tmp> uni(n);
        FOR(i, 0, n-1) {
          r += tran[i][0];
          uni[i] = {tran[i][0], tran[i][1]};
        }
        sort(uni.begin(), uni.end());
        auto check = [&](ll x) {
          ll cur = x;
          for(auto p:uni) {
            cur -= p.cost;
            if(cur < 0) return false;
            cur += p.back;
          }
          return true;
        };
        while(l < r) {
          ll mi = l + (r - l) / 2;
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