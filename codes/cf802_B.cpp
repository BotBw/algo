#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)

const int N = 1e5 + 10;
int n;
char num[N];
char ans[N];

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    scanf("%s", num);
    if(num[0] == '9') {
      bool borrow = 0;
      _FOR(i, n-1, 0) {
        int d1 = 1 - borrow;
        borrow = 0;
        int r1 = d1 - (num[i] - '0');
        if(r1 < 0) {
          r1 += 10;
          borrow = 1;
        }
        ans[i] = r1 + '0';
      }
      FOR(i, 0, n-1) printf("%c", ans[i]);
      puts("");
    } else {
      FOR(i, 0, n-1) printf("%c", '9' - num[i] + '0');
      puts("");
    }
  }
}