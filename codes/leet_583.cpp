#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#endif
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    f[i][j] = f[i-1][j-1] + 1;
                } else {
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
            }
        }
        return n + m - 2*f[n][m];
    }
};
int main() {
  
  return 0;
}
