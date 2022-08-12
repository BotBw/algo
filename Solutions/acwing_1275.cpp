#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxm = 2e5 + 10;
// const int maxm = 10;

ll t[maxm*4];

ll n, m, p;

void push_up(int i) {
  t[i] = max(t[i*2], t[i*2+1]);
}

void update(int p, int val, int tl = 1, int tr = m, int i = 1) {
  if(tl == tr) {
    t[i] = val;
    return;
  }
  int mi = (tl + tr)/2;
  if(p <= mi) update(p, val, tl, mi, i*2);
  else update(p, val, mi+1, tr, i*2+1);
  push_up(i);
}

ll query(int l, int r, int tl = 1, int tr = m, int i = 1) {
  if (l <= tl && tr <= r) {
    return t[i];
  }
  int mi = (tl+tr)/2;
  ll ans = 0;
  if(l <= mi) ans = max(ans, query(l, r, tl, mi, i*2)); 
  if(mi < r) ans = max(ans, query(l, r, mi+1, tr, i*2+1)); 
  return ans;
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> m >> p;
  int a = 0;
  FOR(i ,1 ,m) {
    char op;
    ll arg;
    cin >> op >> arg;
    if(op == 'A') {
      n++;
      ll insert = (arg+a+p)%p;
      update(n, insert);
    } else {
      a = query(n-arg+1, n);
      cout << a << endl;
    }
  }
  return 0;
}
#endif