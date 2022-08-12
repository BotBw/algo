#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG
class Solution {
public:
    long long kMirror(int k, int n) {
        ll ans = 0;
        for(int i = 1; i < 10; i++) {
          if(check(i, k)) {
            ans += i;
            n--;
            if(!n) return ans;
          }
        }
        for(ll w = 0; ; w++) {
          ll lo = pow(10, w), hi = lo*10;

          for(ll i = lo; i < hi; i++) {
            ll j = i, rev = 0;
            while(j) {
              rev *= 10;
              rev += (j%10);
              j /= 10;
            }
            ll val = 1ll*i*hi + rev;
            if(check(val, k)) {
              ans += val;
              n--;
              if(!n) return ans;
            }
          }

          for(ll i = lo; i < hi; i++) {
            ll j = i, rev = 0;
            while(j) {
              rev *= 10;
              rev += (j%10);
              j /= 10;
            }

            for(ll mm = 0; mm < 10; mm++) {
              ll val = (1ll*i*10+mm)*hi+rev;
              if(check(val, k)) {
                ans += val;
                n--;
                if(!n) return ans;
              }
            }
          }
        }
        return ans;
    }

    bool check(ll val, int k) {
      static int arr[128];
      int hi = 0;
      while(val) {
        arr[hi++] = val % k;
        val /= k;
      }
      hi--;
      int lo = 0;
      while(lo < hi) {
        if(arr[lo++] != arr[hi--]) return false;
      }
      return true;
    }
};