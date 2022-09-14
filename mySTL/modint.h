#ifndef MODINT_H
#define MODINT_H

#include <iostream>
#include <vector>
using namespace std;

// modint
struct modint {
  typedef long long ll;
  static int MOD;
  ll val;

  modint(ll v = 0) : val(v % MOD) {
    if (val < 0) val += MOD;
  }

  static void setmod(int _MOD) { MOD = _MOD; }
  static int getmod() { return MOD; }
  void setval(ll _val) { this->val = _val; }
  int getval() const { return val; }
  modint operator-() const { return val ? MOD - val : 0; }
  modint operator+(const modint& r) const {
    return modint(*this) += r;
  }
  modint operator-(const modint& r) const {
    return modint(*this) -= r;
  }
  modint operator*(const modint& r) const {
    return modint(*this) *= r;
  }
  modint operator/(const modint& r) const {
    return modint(*this) /= r;
  }
  modint& operator+=(const modint& r) {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  modint& operator-=(const modint& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  modint& operator*=(const modint& r) noexcept {
    val = (val % MOD) * (r.val % MOD) % MOD;
    return *this;
  }
  modint& operator/=(const modint& r) noexcept {
    ll a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      ll t = a / b;
      a -= t * b, swap(a, b);
      u -= t * v, swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  bool operator==(const modint& r) const noexcept { return this->val == r.val; }
  bool operator!=(const modint& r) const noexcept { return this->val != r.val; }
  friend istream& operator>>(istream& is, modint& x) noexcept {
    is >> x.val;
    x.val %= MOD;
    if (x.val < 0) x.val += MOD;
    return is;
  }
  friend ostream& operator<<(ostream& os, const modint& x) noexcept {
    return os << x.val;
  }
  friend modint modpow(const modint& r, int n) noexcept {
    if (n == 0) return 1;
    if (n < 0) return modpow(modinv(r), -n);
    auto t = modpow(r, n / 2);
    t = t * t;
    if (n & 1) t = t * r;
    return t;
  }
  friend modint modinv(const modint& r) noexcept {
    ll a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      ll t = a / b;
      a -= t * b, swap(a, b);
      u -= t * v, swap(u, v);
    }
    return modint(u);
  }
};

int modint::MOD = 1000000007;

#endif
