#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
unordered_map<int, int> p;
int n;

const int MOD = 1e9 + 7;

int main() {
  scanf("%d", &n);
  while(n--) {
    int x;
    scanf("%d", &x);
    for(int i = 2; i <= x/i; i++) {
      while(x % i == 0) {
        x /= i;
        p[i]++;
      }
    }
    if(x > 1) p[x]++;
  }
  LL ret = 1;
  for(auto pp:p) {
    ret *= (1 + pp.second % MOD % MOD);
    ret %= MOD;
  }
  printf("%lld", ret);
  return 0;
}