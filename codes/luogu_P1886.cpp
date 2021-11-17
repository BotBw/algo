#include <bits/stdc++.h>
#include <deque>

template <typename T>
class MinQueue_id {
private:
  std::deque<int> q;
  T *elem;
  int window_size;
public:
  MinQueue_id(T *_elem, int _window_size): q(), elem(_elem), window_size(_window_size) {}

  void push_id(int id) {
    while(!q.empty() && elem[q.back()] > elem[id]) q.pop_back();
    q.push_back(id);
    if(id-q.front()+1 > window_size) q.pop_front();
  }

  int front_id() const {
    return q.front();
  }

  int size() const {
    return q.size();
  }
};

template <typename T>
class MaxQueue_id {
private:
  std::deque<int> q;
  T *elem;
  int window_size;
public:
  MaxQueue_id(T *_elem, int _window_size): q(), elem(_elem), window_size(_window_size) {}

  void push_id(int id) {
    while(!q.empty() && elem[q.back()] < elem[id]) q.pop_back();
    q.push_back(id);
    if(id-q.front()+1 > window_size) q.pop_front();
  }

  int front_id() const {
    return q.front();
  }

  int size() const {
    return q.size();
  }
};
using namespace std;

int f[(unsigned int)(1e6+5)];
int n, k;
int main() {
 ios::sync_with_stdio(0);
 cin >> n >> k;
 for(int i = 1; i <= n; i++) {
   cin >> f[i];
 }
 MinQueue_id<int> q1(f, k);
 MaxQueue_id<int> q2(f, k);
 for(int i = 1; i <= n; i++) {
   q1.push_id(i);
   if(i >= k) cout << f[q1.front_id()] << ' ';
 }
 cout << '\n';
 for(int i = 1; i <= n; i++) {
   q2.push_id(i);
   if(i >= k) cout << f[q2.front_id()] << ' ';
 }
 return 0;
}