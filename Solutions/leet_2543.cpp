#include "bits/stdc++.h"

class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    bool isReachable(int x, int y) {
        int g = gcd(x, y);
        return (g & (g - 1)) == 0;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}