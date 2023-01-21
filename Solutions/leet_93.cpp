#include "bits/stdc++.h"

class Solution {
public:

    void dfs(const string &s, int i, vector<string> &cur, vector<string> &ans) {
      debug(i, cur);
      if(cur.size() == 4 || i >= (int) s.size()) {
        if(cur.size() != 4) return;
        FOR(j, i, s.size() - 1) cur.back().push_back(s[j]);
        bool valid = true;
        for(auto e : cur) {
          stringstream sstream(e);
          int val;
          sstream >> val;
          if(!(0 <= val && val <= 255) || (e[0] == '0' && val != 0) || (val == 0 && e.size() > 1)) {
            valid = false;
            break;
          }
        }
        debug(cur, valid);
        if(valid) {
          string a;
          string sep = "";
          for(auto e : cur) {
            a += sep;
            a += e;
            sep = ".";
          }
          ans.push_back(a);
        }
        return;
      }
      if(cur.size() && cur.back().size() < 3) {
        cur.back().push_back(s[i]);
        dfs(s, i+1, cur, ans);
        cur.back().pop_back();
      }
      if(!cur.size() || (cur.size() && cur.back().size() > 0)) {
        cur.emplace_back(1, s[i]);
        dfs(s, i+1, cur, ans);
        cur.pop_back();
      }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> cur, ans;
        dfs(s, 0, cur, ans);
        return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Solution s;
  string t1 = "25525511135" ,t2 = "0000";
  // s.restoreIpAddresses(t1);
  s.restoreIpAddresses(t2);
  return 0;
}