#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt;
  cin >> tt;
  FOR(t, 1, tt) {
    int n, r, b;
    cin>>n>>r>>b;
    int p=r/(b+1),q=r%(b+1);
    for(int i=0;i<q;i++)    cout<<string(p+1,'R')<<'B';
    for(int i=q;i<b;i++)    cout<<string(p,'R')<<'B';
    cout<<string(p,'R');
    cout << '\n';
  }
  return 0;
}