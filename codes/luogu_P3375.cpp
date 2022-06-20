#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

string s1, s2;

void KMP(const vector<int> &f) {
  for (int i = 0, j = 0; i < s1.size(); i++) {
    while(j && s1[i] != s2[j]) j = f[j-1];
    if (s1[i] == s2[j]) j++;
    if (j == s2.length()) {
      cout << i - j + 2 << endl;
      j = f[j-1];
    }
  }
}

vector<int> preprocessor() {
  vector<int> f(s2.size(), 0);
  for(int i = 1; i < s2.size(); i++) {
    int j = f[i-1];
    while(j && s2[i] != s2[j]) j = f[j-1];
    if (s2[i] == s2[j]) j++;
    f[i] = j;
  }
  return f;
}

#ifdef LEET
#include "leet.h"
#else
int main() {
  cin >> s1 >> s2;
  auto f = preprocessor();
  KMP(f);
  FOR(i, 0, f.size()-1) cout << f[i] << ' ';
  return 0;
}
#endif