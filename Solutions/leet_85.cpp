#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
// #define DEBUG

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& m) {
    if(!m.size()) return 0;
    int n = m.size()-1;
    int mm = m[0].size()-1;
    int ans = 0;
    vector<int> dp(mm+1, 0);
    FOR(i, 0, n) {
      FOR(j, 0, mm) {
        if(m[i][j] == '0') {
          dp[j] = 0;
        } else {
          dp[j]++;
        }
      }
      ans = max(ans, largestRectangleArea(dp));
    }
    return ans;
  }
  int largestRectangleArea(vector<int>& h) {
    stack<int> s;
    h.push_back(0);
    int n = h.size() - 1;
    int ans = 0;
    FOR(i, 0, n) {
      while (!s.empty() && h[i] <= h[s.top()]) {
        int height = h[s.top()];
        s.pop();
        int l = s.empty() ? -1 : s.top();
        ans = max(ans, (i - (l + 1)) * height);
#ifdef DEBUG
        cout << l << ':' << i << endl;
#endif
      }
      s.push(i);
    }
    return ans;
  }
};