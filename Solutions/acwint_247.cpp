#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for (int i = (a); i >= (b); --i)

const int maxn = 1e4 + 10;
// const int maxn = 10;

vector<double> ys;

struct interval {
  double x1, y1, y2;
  int val;
  bool operator<(const interval &b) const { return x1 < b.x1; }
} itvl[maxn * 2];

struct node {
  int l, r;
  int cnt;
  double len;
} t[maxn * 8];

void push_up(int i) {
  if (t[i].cnt > 0) {
    t[i].len = ys[t[i].r + 1] - ys[t[i].l];
  } else if(t[i].r != t[i].l) {
    t[i].len = t[i * 2].len + t[i * 2 + 1].len;
  } else t[i].len = 0;
}

void build(int i, int l, int r) {
  t[i].l = l;
  t[i].r = r;
  t[i].len = 0;
  t[i].cnt = 0;
  if(l == r) return;
  int mi = (l + r) / 2;
  build(i * 2, l, mi);
  build(i * 2 + 1, mi + 1, r);
}

void update(int i, int l, int r, int k) {
  if (l <= t[i].l && t[i].r <= r) {
    t[i].cnt += k;
    push_up(i);
    return;
  }
  int mi = (t[i].l + t[i].r) / 2;
  if (l <= mi) update(i * 2, l, r, k);
  if (mi < r) update(i * 2 + 1, l, r, k);
  push_up(i);
}

int rnkOf(double d) {
  return lower_bound(ys.begin(), ys.end(), d) - ys.begin();
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  int n;
  int i = 1;
  while (cin >> n) {
    if (n == 0) break;
    ys.clear();
    double ans = 0.0;
    int j = 0;
    FOR(i, 1, n) {
      double x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      itvl[++j] = interval{x1, y1, y2, 1};
      itvl[++j] = interval{x2, y1, y2, -1};
      ys.push_back(y1);
      ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());
    sort(itvl + 1, itvl + j + 1);
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    build(1, 0, ys.size() - 2);

    FOR(i, 1, j) {
      ans += t[1].len * (itvl[i].x1 - itvl[i - 1].x1);
      update(1, rnkOf(itvl[i].y1), rnkOf(itvl[i].y2)-1, itvl[i].val);
    }

    cout << "Test case #" << i << endl;
    printf("Total explored area: %.2f\n\n", ans);
    i++;
  }
  return 0;
}
#endif