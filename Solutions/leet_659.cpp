#include "bits/stdc++.h"

class Solution {
public:
    bool isPossible(vector<int>& a) {
        map<int, int> cnt, good;
        for(auto v:a) cnt[v]++;
        for(auto v:a) {
          if(!cnt[v]) continue;
          cnt[v]--;
          if(good[v-1]) {
            good[v-1]--;
            good[v]++;
          } else if(cnt[v+1] && cnt[v+2]) {
            cnt[v+1]--;
            cnt[v+2]--;
            good[v+2]++;
          } else return false;
        }
        return true;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}