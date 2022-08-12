#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#ifdef LEET
#include "leet.h"
class Solution {
public:
    /*
        if(h[i-1] > h[i] < h[i+1]) h[i] = 1;
        if(h[i] > h[i-1]) f[i] = max(f[i], f[i-1] + 1);
        if(h[i] > h[i+1]) f[i] = max(f[i], f[i+1] + 1);\
        
        
    */
    int candy(vector<int>& h) {
        if(h.size() == 1) return 1;
        vector<int> f(h.size());
        int ans = 0;
        for(int i = 0; i < f.size(); i++) {
            ans += dfs(i, f, h);
            // cout << f[i] << "  ";
        }
        return ans;
    }
    
    int dfs(int x, vector<int> &f, const vector<int> &h) {
        if(f[x] != 0) return f[x];
        if(x == 0) {
            if(h[x] <= h[x+1]) {
                return f[x] = 1;
            } else {
                return f[x] = dfs(x + 1, f, h) + 1;
            }
        } else if (x == f.size()-1) {
            if(h[x-1] >= h[x]) {
                return f[x] = 1;
            } else {
                return f[x] = dfs(x - 1, f, h) + 1;
            }
        } else {
            int l = x - 1, r = x + 1;
            if(h[l] >= h[x] && h[x] <= h[r]) {
                return f[x] = 1;
            }
            if(h[l] < h[x]) f[x] = max(f[x], dfs(l, f, h) + 1);
            if(h[x] > h[r]) f[x] = max(f[x], dfs(r, f, h) + 1);
            return f[x];
        }
    }
    
};
#else
int main() {
  return 0;
}
#endif