#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debug codes are contained, delete this line before submitting
#define DEBUG


int n = 1;

int h[100005];
int seq[100005];

inline bool check1(int a, int target) {
  return target > a;
}

inline bool check2(int a, int target) {
  return a >= target;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while(cin >> h[n]) n++; n--;
  int len = 1;
  seq[1] = h[1];
  FOR(i, 2, n) {
    if(seq[len] >= h[i]) {
      seq[++len] = h[i];
    } else {
      int l = 1, r  = len;
      int ans;
      while(l < r) {
        int mi = (l+r)/2;
        if(check1(seq[mi], h[i])) {
          r = mi;
        } else {
          l = mi + 1;
        }
      }
      seq[l] = h[i];
    }
  }
  cout << len << endl;
  len = 1;
  seq[1] = h[1];
  FOR(i, 2, n) {
    if(seq[len] < h[i]) {
      seq[++len] = h[i];
    } else {
      int l = 1, r  = len;
      int ans;
      while(l < r) {
        int mi = (l+r)/2;
        if(check2(seq[mi], h[i])) {
          r = mi;
        } else {
          l = mi + 1;
        }
      }
      seq[l] = h[i];
    }
  }
  cout << len;
  return 0;
}