#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int max(int n,...) {va_list args;va_start(args, n);int ret = INT_MIN;FOR(i, 0, n-1)ret = max(ret, va_arg(args, int));va_end(args);return ret;}
int min(int n,...) {va_list args;va_start(args, n);int ret = INT_MAX;FOR(i, 0, n-1)ret = min(ret, va_arg(args, int));va_end(args);return ret;}
#define DEBUG // if debugging codes are contained, delete this line before submitting

class Solution {
public:
  struct cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
      if(a[0] == b[0]) return a[1] < b[1];
      return a[0] < b[0];
    }
  };
    int findMinArrowShots(vector<vector<int>>& pts) {
        int n = pts.size();
        sort(pts.begin(), pts.end(), cmp());
        int ans = 1;
        int left = pts[0][1];
        for(int i = 1; i < n; i++) {
          if(pts[i][0] > left) {
            ans++, left = pts[i][1];
          } else {
            left = min(pts[i][1], left);
          }
        }
        return ans;
    }
};