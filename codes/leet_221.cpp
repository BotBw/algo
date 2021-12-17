#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for (int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int x = matrix.size(), y = matrix[0].size();
        vector<vector<int>> opt(x+1, vector(y+1, 0));
        int ans = 0;
        for(int i = 1; i <= x; i++) {
            for(int j = 1; j <= y; j++) {
                if(matrix[i-1][j-1] == '1') opt[i][j]=min(min(opt[i][j-1],opt[i-1][j]),opt[i-1][j-1]) + 1;
                ans=max(ans,opt[i][j]);
            }
        }
        return ans*ans;
    }
};