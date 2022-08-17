#include "bits/stdc++.h"

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& w) {
        set<string> hash;
        vector<string> convert {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int n = w.size();
        FOR(i, 0, n-1) {
          int m = w[i].size();
          string res;
          FOR(j, 0, m-1) {
            res += convert[w[i][j] - 'a'];
          }
          hash.insert(res);
        }
        return hash.size();
    }
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}