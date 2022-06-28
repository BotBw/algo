#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  int tt = 0;
  while(t--) {
    tt++;
    int l, r;
    scanf("%d %d", &l, &r);
    if(l > r) swap(l, r);
    ll ans = 1ll * l * (l + 1)/2;
    printf("Case #%d: %lld\n", tt, ans);
  }
  return 0;
}