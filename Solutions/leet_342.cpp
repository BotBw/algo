#include "bits/stdc++.h"

class Solution {
public:
    bool isPowerOfFour(int n) {
        ll i = 1;
        while(i < n) i *= 4;
        return i == n;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}