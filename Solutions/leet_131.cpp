#include "bits/stdc++.h"

class Solution {
public:
    bool isPalindrome(const string &s) {
      int l = 0, r = s.size() - 1;
      while(l < r) {
        if(s[l] == s[r]) l++, r--;
        else return false;
      }
      return true;
    }
    void dfs(const string &s, int i, vector<string> &cur, vector<vector<string>> &ans) {
      if(i == s.size()) {
        if(isPalindrome(cur.back())) {
          ans.push_back(cur);
        }
        return;
      }
      if(cur.empty() || isPalindrome(cur.back())) {
        cur.emplace_back(1, s[i]);
        dfs(s, i + 1, cur, ans);
        cur.pop_back();
      }

      if(cur.size()) {
        cur.back().push_back(s[i]);
        dfs(s, i + 1, cur, ans);
        cur.back().pop_back();
      }
    }

    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> cur;
      dfs(s, 0, cur, ans);
      return ans;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}