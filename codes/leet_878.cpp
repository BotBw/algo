#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

class Solution {
public:
    const int MOD = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long LCM = lcm(a, b), L = min(a, b), R = n*L, mid, ans;
        while(L <= R) {
            mid = L + (R-L) / 2;
            if((mid/a + mid/b - mid/LCM) < n) L = mid + 1;   // magical numbers <= mid are less than required, so discard search space to left of mid
            else R = mid - 1, ans = mid;                      // mark mid as the potential answer & search in [L, mid-1]
        }
        return ans % MOD;
    }

    int lcm(int a, int b) {
      return a*b/gcd(a,b);
    }

    int gcd(int a, int b) {
      if(a < b) swap(a, b);
      if(a%b == 0) return b;
      return gcd(b, a%b);
    }
};