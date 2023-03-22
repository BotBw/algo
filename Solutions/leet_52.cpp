#include "bits/stdc++.h"

class Solution {
 public:
  struct chess {
    int x;
    int y;
  };
  int totalNQueens(int n) { return _helper(n); }
  bool canPlace(const vector<chess> &chesses, int k, int x, int y) {
    for (int i = 0; i < k; i++)
      if (chesses[i].y == y || abs(chesses[i].y - y) == abs(chesses[i].x - x))
        return false;
    return true;
  }
  void helper(int &ans, vector<chess> &chesses, int k, int n) {
    if (k >= n) {
      ans++;
      return;
    }
    int y = 0;
    for (; y < n; y++) {
      if (canPlace(chesses, k, k, y)) {
        chesses[k] = {k, y};
        helper(ans, chesses, k + 1, n);
      }
    }
  }
  int _helper(int n) {
    int ans = 0;
    vector<chess> ch;
    ch.resize(n);
    stack<pii> p;
    p.push({0, -1});
    int _k, _y;
    while (p.size()) {
    newFrame:
      auto param = p.top();
      _k = param.first, _y = param.second;
      if (_k >= n) {
        ans++;
        p.pop();
        continue;
      }
      int y = _y + 1;
      for (; y < n; y++) {
        if (canPlace(ch, _k, _k, y)) {
          ch[_k] = {_k, y};
          p.pop();
          p.push({_k, y});
          p.push({_k + 1, -1});
          goto newFrame;
        }
      }
      p.pop();
    }
    return ans;
  }
};
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Solution s;
  cout << s.totalNQueens(4) << endl;
  cout << s.totalNQueens(1) << endl;
  return 0;
}