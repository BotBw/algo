#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)
typedef long long LL;

const int N = 2e5 + 10;
int n, q;
LL v[N], s[N];

int main() {
  cin >> n;
  FOR(i, 1, n) scanf("%lld", v + i), s[i] = s[i-1] + v[i];
  LL maxT = 0;
  FOR(i, 1, n) maxT = max(maxT, (s[i] + i - 1)/i);
  cin >> q;
  FOR(j, 1, q) {
    int tj;
    scanf("%d", &tj);
    if(tj < maxT) {
      puts("-1");
      continue;
    }
    printf("%lld\n", (s[n] + tj - 1)/tj);
  } 
  return 0;
}