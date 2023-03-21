#include "bits/stdc++.h"

class Solution {
public:
  int distMoney(int money, int children) {
    money -= children;
    if(money < 0) return -1;
    int ans = min(children, money / 7);
    money -= ans * 7;
    int dollar1 = children - ans;
    if(dollar1 == 0 && money != 0) return ans - 1;
    if(dollar1 == 1 && money == 3) return ans - 1;
    return ans;
  }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}