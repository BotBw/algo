#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

const int maxn = 105;

int h[maxn], n, f1[maxn], f2[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  FOR(i, 1, n) cin >> h[i];
  FOR(i, 1, n) {
    int maxF1 = 0;
    FOR(j, 1, i-1) {
      if(h[j] < h[i])
        maxF1 = max(maxF1, f1[j]);
    }
    f1[i] = maxF1 + 1;
  }
  _FOR(i, n, 1) {
    int maxF2 = 0;
    _FOR(j, n, i+1) {
      if(h[i] > h[j])
        maxF2 = max(maxF2, f2[j]);
    }
    f2[i] = maxF2 + 1;
  }

  int remnant = 0;

  FOR(i, 1, n) {
    remnant = max(remnant, f1[i] + f2[i]-1);
  }
  cout << n - remnant;
  return 0;
}