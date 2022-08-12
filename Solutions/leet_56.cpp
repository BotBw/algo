#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int max(int n,...) {va_list args;va_start(args, n);int ret = INT_MIN;FOR(i, 0, n-1)ret = max(ret, va_arg(args, int));va_end(args);return ret;}
int min(int n,...) {va_list args;va_start(args, n);int ret = INT_MAX;FOR(i, 0, n-1)ret = min(ret, va_arg(args, int));va_end(args);return ret;}
#define DEBUG // if debugging codes are contained, delete this line before submitting

class Solution {
 public:
  static bool cmp(const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; }
  vector<vector<int>> merge(vector<vector<int>> &inte) {
    sort(inte.begin(), inte.end(), cmp);
    vector<vector<int>> ans;
    int c_b = inte[0][0], c_e = inte[0][1];
    FOR(i, 1, inte.size()-1) {
      if(inte[i][0] <= c_e) {
        c_e = max(c_e, inte[i][1]);
      } else {
        ans.push_back({c_b, c_e});
        c_b = inte[i][0];
        c_e = inte[i][1];
      }
    }
    ans.push_back({c_b, c_e});
    return ans;
  }
};