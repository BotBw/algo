#include "bits/stdc++.h"
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> cnt;
        for(auto v:arr) cnt[v]++;
        priority_queue<int> q;
        for(auto p:cnt) {
          q.push(p.second);
        }
        int cur = 0;
        int res = 0;
        while(q.size()) {
          int c = q.top();
          q.pop();
          cur += c;
          res++;
          if(cur >= arr.size() / 2) return res;
        }
        return -1;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}