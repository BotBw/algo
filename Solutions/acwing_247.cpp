#include "bits/stdc++.h"

struct seg {
  double x, y_hi, y_lo;
  int w;
  bool operator<(const seg &o) const {
    return x < o.x;
  }
};

struct node {
  int l, r;
  int w_sum;
  double len;
  double valid_len;
};

vector<node> t;

#define lc(x) ((x) * 2)
#define rc(x) ((x) * 2 + 1)

vector<double> uniy;

void build(int i, int l, int r) {
  t[i] = {l, r, 0, 0, 0};
  if(l == r) {
    t[i].len = uniy[r + 1] - uniy[l];
    return;
  }
  int mi = (l + r) / 2;
  build(lc(i), l, mi);
  build(rc(i), mi + 1, r);
  t[i].len = t[lc(i)].len + t[rc(i)].len;
}

void push_valid(int x) {
  if(t[x].w_sum > 0) {
    t[x].valid_len = t[x].len;
  } else {
    if(t[x].l != t[x].r) { // w_sum == 0
      t[x].valid_len = t[lc(x)].valid_len + t[rc(x)].valid_len;
    } else {
      t[x].valid_len = 0;
    }
  }
}

void update(int i, int l, int r, int w) {
  if(l <= t[i].l && t[i].r <= r) {
    t[i].w_sum += w;
    push_valid(i);
  debug(t[i].l, t[i].r, t[i].w_sum, t[i].valid_len, t[i].len);
    return;
  }
  int mi = (t[i].l + t[i].r) / 2;
  if(l <= mi) update(lc(i), l, r, w);
  if(r >= mi + 1) update(rc(i), l, r, w);
  push_valid(i);
  debug(t[i].l, t[i].r, t[i].w_sum, t[i].valid_len, t[i].len);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  int _ = 0;
  while(cin >> n && n != 0) {
    _++;
    uniy.clear();
    vector<seg> segs;
    FOR(i, 1, n) {
      double x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      uniy.push_back(y1), uniy.push_back(y2);
      segs.push_back({x1, y2, y1, 1});
      segs.push_back({x2, y2, y1, -1});
    }
    sort(begin(uniy), end(uniy));
    uniy.erase(unique(begin(uniy), end(uniy)), end(uniy));
    sort(begin(segs), end(segs));
    auto rankY = [&](double yi) {
      return lower_bound(begin(uniy), end(uniy), yi) - begin(uniy);
    };

    t = vector<node>(uniy.size() * 4);

    build(1, 0, uniy.size() - 2);

    int rnklo = rankY(segs[0].y_lo);
    int rnkhi = rankY(segs[0].y_hi) - 1;
    if(rnklo <= rnkhi) update(1, rnklo, rnkhi, segs[0].w);

    double sum = 0;

    FOR(i, 1, segs.size() - 1) {
      rnklo = rankY(segs[i].y_lo);
      rnkhi = rankY(segs[i].y_hi) - 1;
      sum += (segs[i].x - segs[i-1].x) * t[1].valid_len;
      if(rnklo <= rnkhi) update(1, rnklo, rnkhi, segs[i].w);
    }

    cout << "Test case #" << _ << '\n';
    cout << "Total explored area: " << fixed << setprecision(2) << sum << "\n\n";
  }
  return 0;
}