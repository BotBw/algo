#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)
typedef long long ll;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    ll d1;
    cin >> d1;
    ll preA = d1;
    ll ans = 0;
    FOR(i, 2, n) {
      ll a;
      cin >> a;
      ll di = a - preA;
      preA = a;
      if(di < 0) {
        d1 += di;
        ans -= di;
      } else if(di > 0) {
        ans += di;
      }
    }
    ans += abs(d1);
    printf("%lld\n", ans);
  }
}