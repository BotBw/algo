#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  int cases = 0;
  scanf("%d", &T);
  while(T--) {
    cases++;
    int n, m;
    scanf("%d %d", &n, &m);
    int sum = 0;
    for(int i = 1; i <= n; i++) {
      int c;
      scanf("%d", &c);
      sum += c;
    }
    printf("Case #%d: %d\n", cases, sum % m);
  }
  
  return 0;
}