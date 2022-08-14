#include "bits/stdc++.h"

class Solution {
public:
    int countSpecialNumbers(int n) {
        vector<int> dg;
        while(n) {
          dg.push_back(n % 10);
          n /= 10;
        }
        const int N = 11;
        int C[N][N];
        int fac[N];
        memset(C, 0, sizeof C);
        memset(fac, 0, sizeof fac);
        FOR(i, 0, N-1) C[i][0] = 1;
        FOR(i, 1, N-1) {
          FOR(j, 1, i) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
          }
        }
        fac[0] = 1;
        FOR(i, 1, N-1) fac[i] = i * fac[i-1];
        int res = 0, m = dg.size();
        for(int i = 0; i < m-1; i++) {
          int inc = 9;
          for(int j = i - 1, k = 9; j >= 0; j--, k--) {
            inc *= k;
          }
          res += inc;
        }
        set<int> used;
        for(int i = m - 1; i >= 0; i--) {
          int x = dg[i];
          for(int k = (i == m-1); k < x; k++) {
            if(!used.count(k)) {
              res += C[10 - used.size() - 1][i] * fac[i];
            }
          }
          if(used.count(x)) break;
          if(i == 0) res++;
          used.insert(x);
        }
        return res;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}