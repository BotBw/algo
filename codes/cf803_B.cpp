#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)

const int N = 2e5 + 10;
int a[N];
int n, k;
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    cin >> n >> k;
    FOR(i, 1, n) scanf("%d", a + i);
    if(k == 1) {
      if(n % 2) printf("%d\n", n/2);
      else printf("%d\n", n/2 - 1);
      continue;
    }
    int cnt = 0;
    FOR(i, 2, n-1)
      if(a[i-1] + a[i+1] < a[i]) cnt++;
    printf("%d\n", cnt);
  }
}