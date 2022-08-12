#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

bool isPrime(int n) {
  if(n < 2) return false;
  for(int i = 2; i * i <= n; i++) {
    if(n % i == 0) return false;
  }
  return true;
}
#ifdef LEET
#include "leet.h"
#else
int main() {
  int n;
  cin >> n;
  if(isPrime(n)) {
    if(isPrime(n-6)) {
      cout << "Yes" << endl << n-6;
      return 0;
    }
    if(isPrime(n + 6)) {
      cout << "Yes" << endl << n+6;
      return 0;
    }
  }
  for(int i = n + 1; ; i++) {
    if(isPrime(i) && (isPrime(i-6) || isPrime(i+6))) {
      cout << "No\n" << i;
      return 0;
    }
  }
  return 0;
}
#endif