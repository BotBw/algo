#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

class Solution {
public:
    const int modulo = 1e9+7;
    ll numTilings(int n) {
        vector<ll> up(n+1), down(n+1), both(n+1);
        both[1] = 1;
        up[0] = 0;
        down[1] = 0;
        FOR(i, 2, n) {
          both[i] = (both[i-1] + both[i-2] + up[i-1] + down[i-1])%modulo;
          up[i] = (down[i-1] + both[i-2])%modulo;
          down[i] = (up[i-1] + both[i-2])%modulo;
        }
        return both[n];
    }
};