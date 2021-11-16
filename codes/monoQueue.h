#include <deque>

template <typename T>
class MinQueue_id {
private:
  std::deque<int> q;
  T *elem;
  int window_size; // 0 to cancel the window
public:
  MinQueue_id(T *_elem, int _window_size): q(), elem(_elem), window_size(_window_size) {}

  void push_id(int id) {
    while(!q.empty() && elem[q.back()] > elem[id]) q.pop_back();
    q.push_back(id);
    if(!q.empty() && window_size > 0 && id-q.front()+1 > window_size) q.pop_front();
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
  int window_size;  // 0 to cancel the window
public:
  MaxQueue_id(T *_elem, int _window_size): q(), elem(_elem), window_size(_window_size) {}

  void push_id(int id) {
    while(!q.empty() && elem[q.back()] < elem[id]) q.pop_back();
    q.push_back(id);
    if(!q.empty() && window_size > 0 && id-q.front()+1 > window_size) q.pop_front();
  }

  int front_id() const {
    return q.front();
  }

  int size() const {
    return q.size();
  }
};