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
    vector<vector<int>> permuteUnique(vector<int>& ns) {
        vector<int> per(ns.size()), id(ns.size());
        vector<vector<int>> ans;
        vector<bool> vis(ns.size());
        work(0, per, id, ns, vis, ans);
        return ans;
    }
    
    void work(int x, vector<int> &per, vector<int> &id, vector<int> &ns, vector<bool> &vis, vector<vector<int>> &ans) {
        if(x == ns.size()) {
            ans.emplace_back(per);
            return;
        }
        for(int i = 0; i < ns.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                bool use = true;
                for(int j = x - 1; j >= 0; j--) {
                    if(per[j] == ns[i] && id[j] > i) {
                        use = false;
                        break;
                    } 
                }
                if(use) {
                    id[x] = i;
                    per[x] = ns[i];
                    work(x + 1, per, id, ns, vis, ans);
                }            
                vis[i] = false;
            }
        }
    }
};
#else
int main() {
  return 0;
}
#endif