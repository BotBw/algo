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
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        multiset<int> s;
        vector<vector<int>> ans;
        vector<vector<int>> ord;
        for(int i = 0; i < b.size(); i++) {
            ord.push_back({b[i][0], b[i][2]});
            ord.push_back({b[i][1], -b[i][2]});
        }
        sort(ord.begin(), ord.end());

        int i = 0;
        bool init = true;
        int prev = 0;
        s.insert(0);
        while(i < ord.size()) {
            int j = i;
            while(j < ord.size() && ord[j][0] == ord[i][0]) {
                if(ord[j][1] > 0) {
                    s.insert(ord[j][1]);
                } else {
                    s.erase(s.lower_bound(-ord[j][1]));
                }
                j++;
            }
            if(init) {
                prev = *s.rbegin();
                init = false;
                ans.push_back({ord[j-1][0], *s.rbegin()});
            } else {
                if(prev != *s.rbegin()) {
                    ans.push_back({ord[j-1][0], *s.rbegin()});
                    prev = *s.rbegin();
                }
            }
            i = j;
        }
        return ans;
    }
};
#else
int main() {
  return 0;
}
#endif