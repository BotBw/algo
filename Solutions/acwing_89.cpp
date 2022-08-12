#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p;

ll poww(ll a, ll b) {
  if(b == 0) return 1ll % p;
  if(b % 2) return a * poww(a, b-1) % p;
  else {
    ll ret = poww(a, b/2) % p;
    return ret * ret % p;
  }
}

int main() {
  ll a, b;
  cin >> a >> b >> p;
  cout << poww(a, b);
  return 0;
}