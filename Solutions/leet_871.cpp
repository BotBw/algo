#include "bits/stdc++.h"

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& sta) {
        int cur = startFuel;
        int n = sta.size(), res = 0;
        sta.push_back({target, 0});
        priority_queue<int> q;
        FOR(i, 0, n) {
          while(q.size() && cur < sta[i][0]) {
            cur += q.top();
            q.pop();
            res++;
          }
          if(cur < sta[i][0]) return -1;
          q.push(sta[i][1]);
        }
        return res;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}