#include "bits/stdc++.h"

class Solution {
public:
    long long maximumBeauty(vector<int>& a, long long newFlowers, int target, int full, int partial) {
        int n = a.size();
        ll res = 0;
        sort(a.begin(), a.end());
        vector<ll> pre(n), dp(n);
        pre[0] = a[0];
        FOR(i, 1, n-1) pre[i] = pre[i-1] + a[i];
        int k = n-1;
        while(k >= 0 && a[k] >= target) k--;
        k++;
        if(k == 0) return (ll) n * full;
        FOR(i, 1, k-1) {
          dp[i] = dp[i-1] + i * (a[i] - a[i-1]);
        }
        debug(k, a, dp);
        _FOR(i, k-1, 0) {
          ll rem = newFlowers - ((ll)(k - 1 - i) * target -  (pre[k-1] - pre[i]));
          if(rem < 0) break;
          int l = 0, r = i;
          auto check = [&](int mi) {
            return dp[mi] <= rem;
          };
          while(l < r) {
            int mi = (l + r + 1) / 2;
            if(check(mi)) l = mi;
            else r = mi - 1;
          }
          rem -= dp[l];
          ll mn = a[l];
          if(mn + rem / (l + 1) < target) mn += rem / (l + 1);
          else mn = target - 1;
          debug(i, mn, l, rem);
          ll cur = (ll)(n-1-i)*full + (ll)mn * partial;
          res = max(res, cur);
          debug(cur);
        }
        ll rem = newFlowers - ((ll)k * target - pre[k-1]);
        if(rem >= 0) res = max(res, (ll)n * full);
        return res;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  vector<int> a = {5,19,1,1,6,10,18,12,20,10,11};
  // cout << s.maximumBeauty(a, 6, 20, 3, 11) << endl;
  a = {18,16,10,10,5};
  // cout << s.maximumBeauty(a, 10, 3, 15, 4) << endl;
  a = {36131,31254,5607,11553,82824,59230,40967,69571,36874,38700,81107,28500,61796,54371,23405,51780,75265,37257,86314,32258,47254,76690,18014,21538,96700,15094,57253,57073,7284,24501,21412,69582,15724,43829,81444,78281,88953,6671,94646,31037,89465,86033,27431,30774,48592,26067};
  cout << s.maximumBeauty(a, 2304903454, 48476, 5937, 15214) << endl;

  return 0;
}