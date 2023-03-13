#include "bits/stdc++.h"

void solve() {
  int n;
  cin >> n;

  vector<int> dig;

  while(n) {
    dig.push_back(n % 10);
    n /= 10;
  }

  int sum = accumulate(dig.begin(), dig.end(), 0);

  int a = sum / 2 + sum % 2;
  int b = sum - a;

  int cur = 0;

  int x = 0;

  int i = 0;
  for(;i < dig.size(); i++) {
    if(cur + dig[i] < a) {
      cur += dig[i];
      x += dig[i] * pow(10, i);
    } else {
      x += max(0, a - cur) * pow(10, i);
      dig[i] -= max(0, a - cur);
      break;
    }
  }
  int y = 0;
  for(;i < dig.size(); i++) {
    y += dig[i] * pow(10, i);
  }
  cout << x << " " << y << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}