#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
          if(a[i][0] > b[j][1]) {
            j++;
          } else if(b[j][0] > a[i][1]) {
            i++;
          } else {
            int begin = max(a[i][0], b[j][0]);
            int end = min(a[i][1], b[j][1]);
            ans.push_back({begin, end});
            a[i][1] <= b[j][1] ? i++ : j++;
          }
        }
        return ans;
    }
};