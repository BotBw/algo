#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) assert((a) <= (b)); for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) assert((a) >= (b)); for(int i = (a); i >= (b); --i)
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    int zeros = 0;
    FOR(i, 1, n) {
      int x; 
      cin >> x;
      arr[i] = x;
      if(x == 0) zeros++;
    }
    if(zeros == 0) {
      puts("1");
      continue;
    }
    if(zeros == n) {
      puts("0");
      continue;
    }
    if(arr[1] == 0 && arr[n] != 0) {
      // debug(arr[1], arr[n]);
      int cnt = 0;
      FOR(i, 1, n) {
        if(arr[i] == 0) cnt++;
        else break;
      }
      if(cnt == zeros) puts("1");
      else puts("2");
    } else if(arr[n] == 0 && arr[1] != 0) {
      int cnt = 0;
      _FOR(i, n, 1) {
        if(arr[i] == 0) cnt++;
        else break;
      }
      if(cnt == zeros) puts("1");
      else puts("2");
    } else {
      int cnt1 = 0,cnt2 = 0;
      FOR(i, 1, n) {
        if(arr[i] == 0) cnt1++;
        else break;
      }
      _FOR(i, n, 1) {
        if(arr[i] == 0) cnt2++;
        else break;
      }
      // debug(cnt1, cnt2);
      if(cnt1 + cnt2 == zeros) puts("1");
      else puts("2");
    }
  }
  return 0;
}