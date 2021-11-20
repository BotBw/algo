#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

struct rod {
  int l, w;
  bool operator<(const rod& b) const {
    if(l == b.l) return w > b.w;
    return l > b.l;
  }
} rods[5005];

int n, f[5005];

int main() {
  cin >> n;
  FOR(i, 1, n) cin >> rods[i].l >> rods[i].w;
  sort(rods+1, rods+n+1);
  int len = 1;
  f[len] = rods[1].w;
  FOR(i, 2, n) {
    if(f[len] < rods[i].w) {
      f[++len] = rods[i].w;
    } else {
      int l = 1, r = len;
      while(l < r) {
        int mi = (l+r)/2;
        if(f[mi] >= rods[i].w) { 
          r = mi;
        } else {
          l = mi + 1;
        }
      }
      f[l] = rods[i].w;
    }
  }
  cout << len;
  return 0;
}