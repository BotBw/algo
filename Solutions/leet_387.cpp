#include "bits/stdc++.h"

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> cnt;
        for(auto c:s) cnt[c]++;
        for(int i = 0; i < s.size(); i++) {
          if(cnt[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}