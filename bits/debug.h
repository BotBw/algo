#ifndef DEBUG_H
#define DEBUG_H

#include <string>
#include <iostream>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(char c) {
  return "\'" + string(1,c) + "\'";
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

string to_string(const vector<bool> &a) {
  vector<int> res;
  for(int i = 0; i < (int)a.size(); i++) {
    res.push_back(a[i]);
  }
  return to_string(res);
}

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#endif