#include "bits/stdc++.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26);
        for(auto c:magazine) {
          cnt[c - 'a']++;
        }
        for(auto c:ransomNote) {
          cnt[c - 'a']--;
          if(cnt[c - 'a'] < 0) return false;
        }
        return true;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}