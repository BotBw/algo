#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#endif

const int N = 1010;
int n, m, q;
int b[N][N];


void update(int x1, int y1, int x2, int y2, int val) {
  b[x1][y1] += val;
  b[x2+1][y1] -= val;
  b[x1][y2+1] -= val;
  b[x2+1][y2+1] += val;
}

int main() {
  cin >> n >> m >> q;
  FOR(i, 1, n) {
    FOR(j, 1, m) {
      int val;
      cin >> val;
      update(i, j, i, j, val);
    }
  }

  FOR(i, 1, q) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    update(x1, y1, x2, y2, c);
  }

  FOR(i, 1, n ) {
    FOR(j, 1, m) {
      b[i][j] += (b[i-1][j] + b[i][j-1] - b[i-1][j-1]);
      cout << b[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
