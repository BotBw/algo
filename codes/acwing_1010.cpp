#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> a(1);
  int h;
  while(cin >> h) {
    a.push_back(h);
  }
  vector<int> work;
  int n = a.size()-1;
  FOR(i, 1, n) {
    if(work.empty() || a[i] <= work.back()) {
      work.push_back(a[i]);
    } else {
      auto it = lower_bound(work.rbegin(), work.rend(), a[i]);
      it--;
      *it = a[i];
    }
  }
  cout << work.size() << endl;
  work.clear();
  FOR(i, 1, n) {
    if(work.empty() || a[i] > work.back()) {
      work.push_back(a[i]);
    } else {
      *lower_bound(work.begin(), work.end(), a[i]) = a[i];
    }
  }
  cout << work.size();
  return 0;
}