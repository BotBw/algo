#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)


const int maxn = 5e4 + 1;
// const int maxn = 50 + 1;

const int maxyear = 1e9+10, minyear = -maxyear;
int n, m;

struct record {
  int year, rain;
  bool operator<(const record &b) const {
    return year < b.year;
  }
} rec[maxn];

int t[maxn*4];

void build(int i, int tl, int tr) {
  if (tl == tr) {
    t[i] = rec[tl].rain;
    return;
  }
  int mi = (tl+tr)/2;
  build(i*2, tl, mi);
  build(i*2 + 1, mi + 1, tr);
  t[i] = max(t[i*2], t[i*2+1]);
}

int query(int i, int tl, int tr, int l, int r) {
  if (l <= tl && tr <= r) {
    return t[i];
  }
  int tmi = (tl+tr)/2;
  int ans = 0;
  if (l <= tmi) {
    ans = max(ans, query(i*2, tl, tmi, l, r));
  }
  if(tmi + 1 <= r) {
    ans = max(ans, query(i*2+1, tmi+1, tr, l, r));
  }
  return ans;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  rec[1].year = minyear;
  rec[n+2].year = maxyear;
  FOR(i, 2, n + 1) {
    cin >> rec[i].year >> rec[i].rain;
  }
  build(1, 1, n+2);
  cin >> m;
  FOR(i, 1, m) {
    int Y, X;
    cin >> Y >> X;
    int rnkY = distance(rec, lower_bound(rec + 1, rec + n + 2 + 1, record{Y, -1}));
    int rnkX = distance(rec, lower_bound(rec + 1, rec + n + 2 + 1, record{X, -1}));
    bool validX = (rnkX != n + 3 && X == rec[rnkX].year);
    bool validY = (rnkY != n + 3 && Y == rec[rnkY].year);
    if (!validX && !validY) {
      cout << "maybe\n";
    } else if (validX && !validY) {
      auto maxx = query(1, 1, n+2, rnkY, rnkX-1);
      if (maxx >= rec[rnkX].rain) {
        cout << "false\n";
      } else {
        cout << "maybe\n";
      }
    } else if (!validX && validY) {
      auto maxx = query(1, 1, n+2, rnkY+1, rnkX-1);
      if (maxx >= rec[rnkY].rain) {
        cout << "false\n";
      } else
        cout << "maybe\n";
    } else {
      auto maxx = query(1, 1, n+2, rnkY+1, rnkX-1);
      bool continous = (X - Y) == (rnkX - rnkY);
      if (rec[rnkX].rain > rec[rnkY].rain || maxx >= rec[rnkX].rain) {
        cout << "false\n";
      } else {
        if (continous) {
          cout << "true\n";
        } else {
          cout << "maybe\n";
        }
      }
    }
    cout << flush;
  }
  return 0;
}
#endif