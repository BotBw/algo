#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)

const int N = 105;
int a[N], n;

int main() {
  int t;
  scanf("%d", &t);
  int sum = 0;
  while(t--) {
    scanf("%d", &n);
    FOR(i, 1, n) {
      scanf("%d", a + i);
      sum ^= a[i];
    }
    FOR(i, 1, n) {
      int x = a[i];
      if((sum ^ a[i]) == a[i]) {
        printf("%d\n", x);
        break;
      }
    }
  }
}