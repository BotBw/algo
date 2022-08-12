#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

const int maxq = 1e5 + 5;

ll t[maxq*4];

int tt, Q, M;

void build(int id, int l, int r) {
  if(l==r){
    t[id] = 1;
    return;
  }
  int mi = (l + r)/2;
  build(id*2, l, mi);
  build(id*2 + 1, mi+1, r);
  t[id] = (t[id*2]*t[id*2+1])%M;
}

void update(int i, int tl, int tr, int l, int r, int mul) {
  if(l <= tl && tr <= r) {
    t[i] = mul;
    return;
  }
  int mi = (tl + tr)/2;
  if(l <= mi) update(i*2, tl, mi, l, r, mul);
  if(mi < r) update(i*2 + 1, mi+1, tr, l, r, mul);
  t[i] = (t[i*2]*t[i*2+1])%M;
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> tt;
  FOR(t_i, 1, tt) {
    cin >> Q >> M;

    build(1, 1, Q);

    FOR(i, 1, Q) {
      int op, m;
      cin >> op >> m;
      if(op == 1) {
        update(1, 1, Q, i, i, m);
      } else {
        update(1, 1, Q, m, m, 1);
      }
      cout << t[1] << endl;
    }
  }
  return 0;
}
#endif