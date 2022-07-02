#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)

const int N = 55;
int a[N];
int n;



int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    int minx = INT_MAX, mini = -1;
    FOR(i, 1, n) {
      int x;
      cin >> x;
      if(minx > x){
        minx = x;
        mini = i;
      }
    }
    if(n % 2) puts("Mike");
    else {
      // printf("%d %d\n", minx, mini);
      if(mini % 2) puts("Joe");
      else puts("Mike");
    }
  }
  return 0;
}