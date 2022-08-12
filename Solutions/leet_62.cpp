#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _for(i, a, b) for(int i = (a); i >= (b); --i)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));
        f[1][1] = 1;
        for(i, 1, m) {
          for(j, 1, n) {
            if(i == 1 && j == 1) continue;
            f[i][j] = f[i-1][j] + f[i][j-1];
          }
        }
        return f[m][n];
    }
};