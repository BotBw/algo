#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

class Solution {
public:
    vector<int> *parr;
    bool canReach(vector<int>& arr, int start) {
        parr = &arr;
        vector<int> vis(arr.size());
        dfs(start, vis);
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0 && vis[i]) return true;
        }
        return false;
    }
    
    void dfs(int u, vector<int>& vis) {
        vis[u] = 1;
        int left = u-(*parr)[u];
        int right = u+(*parr)[u];
        if(left >= 0 && !vis[left]) dfs(left, vis);
        if(right < parr->size() && !vis[right]) dfs(right, vis);
    }

};