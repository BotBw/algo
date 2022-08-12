#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, p;
int a[N], s[N];

int main() {
  int T;
  scanf("%d" ,&T);
  for(int t = 1; t <= T; t++) {
    scanf("%d %d", &n, &p);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    int cur = 0;
    int ans = 0x3f3f3f3f;
    for(int l = 1, r = 1; r <= n; r++) {
      cur += a[r];
      while(l <= r && r - l + 1 > p) {
        cur -= a[l];
        l++;
      }
      if(r - l + 1 == p) ans = min(ans, p * a[r] - cur);
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}