#include "bits/stdc++.h"

class Solution {
public:
    string breakPalindrome(string str) {
        int n = str.size();
        if(n == 0 || n == 1) return "";
        int l = 0, r = n - 1;
        while(l < r && str[l] == 'a') l++, r--;
        if(r <= l) r++, l--;
        if(str[l] == 'a') str[n-1] = 'b';
        else str[l] = 'a';
        return str;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}