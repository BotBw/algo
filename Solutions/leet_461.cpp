#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x^y;
        int ans = 0;
        #ifdef DEBUG
        cout << tmp << endl;
        #endif
        for(; tmp >= 0; tmp = (tmp >> 1)) {
          ans += (tmp & 1);
        }
        return ans;   
    }
};