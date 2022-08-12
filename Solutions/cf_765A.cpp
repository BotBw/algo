#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)
const int N = 105;
int n, l;
int ar[N];

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> l;
    FOR(i, 1, n) cin>> ar[i];
    int res = 0;
    FOR(i, 0, l-1) {
      int zeros = 0, ones = 0;
      FOR(j, 1, n) {
        if((ar[j] >> i) & 1) ones++;
        else zeros++;
      }
      res |= (zeros < ones) << i;
    }
    printf("%d\n", res);
  }
  return 0;
}