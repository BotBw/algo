#ifndef SET_H
#define SET_H

#include <cstdio>
#include <cstdlib>
#include <functional>

template <class KEY, class _compare = std::less<KEY> >
class set {
  // random_num 保证Treap是大根堆
 public:
  struct node {
    KEY key;
    bool isInfinity;
    size_t random_num, size;
    node *left, *right;

    explicit node(KEY _key, node *l, node *r, size_t sz)
        : key(_key), random_num(rand()), size(sz), left(l), right(r) {}
  };

 private:
  static _compare CMP;
  node *root;
  node *left_end_node;
  node *right_end_node;

  void zig(node *&x) {  // 默认x有左子树，右旋
    node *p = x->left;
    x->left = p->right == right_end_node ? left_end_node : p->right;
    p->right = x;
    x = p;
    push_up(x->right);
    push_up(x);
  }

  void zag(node *&x) {  // 默认x有右子树， 左旋
    node *p = x->right;
    x->right = p->left == left_end_node ? right_end_node : p->left;
    p->left = x;
    x = p;
    push_up(x->left);
    push_up(x);
  }

  void push_up(node *rt) {  // 更新节点信息
    if (rt == left_end_node || rt == right_end_node) return;
    int sz = 1;
    if (rt->left) sz += rt->left->size;
    if (rt->right) sz += rt->right->size;
    rt->size = sz;
  }

  node *get_node(KEY key) {
    return new node(key, left_end_node, right_end_node, 1);
  }  // 获得一个树中节点（非左右哨兵）

  void insert(node *&x, KEY key) {
    if (x == left_end_node || x == right_end_node) {
      x = get_node(key);
      return;
    }
    if (key == x->key) {
      return;
    } else if (CMP(key, x->key)) {
      insert(x->left, key);
      if (x->left->random_num > x->random_num) zig(x);
    } else {
      insert(x->right, key);
      if (x->right->random_num > x->random_num) zag(x);
    }
    push_up(x);
  }

  void erase(node *&x, KEY key, bool deleteRight) {
    if (x == left_end_node || x == right_end_node) return;
    if (key == x->key) {
      if (x->left != left_end_node || x->right != right_end_node) {
        if (x->right == right_end_node ||
            x->left->random_num > x->right->random_num) {
          zig(x);
          erase(x->right, key, true);
        } else {
          zag(x);
          erase(x->left, key, false);
        }
      } else {
        delete x;
        x = deleteRight ? right_end_node : left_end_node;
      }
    } else if (CMP(key, x->key)) {
      erase(x->left, key, false);
    } else {
      erase(x->right, key, true);
    }
    // push_up(x);
  }

  node *get_next(node *x, KEY key) const {
    if (x == left_end_node || x == right_end_node) return x;
    if (!CMP(key, x->key)) {  // key >= x->key
      return get_next(x->right, key);
    } else {
      node *ret = get_next(x->left, key);
      if (ret == left_end_node || ret == right_end_node)
        return x;
      else
        return CMP(ret->key, x->key) ? ret : x;
    }
  }

  node *lower_bound(node *x, KEY key) const {
    if (x == left_end_node || x == right_end_node) return x;
    if (CMP(x->key, key)) {  // x->key < key
      return lower_bound(x->right, key);
    } else {
      node *ret = lower_bound(x->left, key);
      if (ret == left_end_node || ret == right_end_node)
        return x;
      else
        return CMP(ret->key, x->key) ? ret : x;
    }
  }

  node *get_prev(node *x, KEY key) const {
    if (x == left_end_node || x == right_end_node) return x;
    if (!CMP(x->key, key)) {
      return get_prev(x->left, key);
    } else {
      node *ret = get_prev(x->right, key);
      if (ret == right_end_node || ret == left_end_node)
        return x;
      else
        return CMP(x->key, ret->key) ? ret : x;
    }
  }

  void destory(node *x) {
    if (x == right_end_node || x == left_end_node) return;
    if (x->left != left_end_node) destory(x->left);
    if (x->right != right_end_node) destory(x->right);
    delete x;
  }

  node *find_key(node *x, KEY key) const {
    if (x == left_end_node || x == right_end_node) return x;
    if (!CMP(x->key, key) && !CMP(key, x->key))
      return x;
    else if (CMP(key, x->key))
      return find_key(x->left, key);
    else
      return find_key(x->right, key);
  }

 private:
  node *get_next(KEY key) const {
    node *ret = get_next(root, key);
    if (ret == left_end_node || ret == right_end_node) return right_end_node;
    return ret;
  }

  node *get_prev(KEY key) const {
    node *ret = get_prev(root, key);
    if (ret == left_end_node || ret == right_end_node) return right_end_node;
    return ret;
  }

  node *find_key(KEY key) const {
    node *ret = find_key(root, key);
    if (ret == left_end_node || ret == right_end_node) return right_end_node;
    return ret;
  }

  node *get_begin_node() const { return left_end_node; }
  node *get_end_node() const { return right_end_node; }

 public:
  set()
      : left_end_node(new node(KEY(), nullptr, nullptr, 0)),
        right_end_node(new node(KEY(), nullptr, nullptr, 0)) {
    root = right_end_node;
  }
  ~set() {
    destory(root);
    delete left_end_node;
    delete right_end_node;
  }
  void insert(KEY key) { insert(root, key); }
  void erase(KEY key) { erase(root, key, true); }
  size_t size() const { return root->size; }
  bool empty() const { return root->size == 0; }

  struct iterator {
    node *pNode;
    const set<KEY, _compare> *tree;

    iterator &operator++() {
      if (pNode == tree->get_end_node()) assert(false);
      pNode = tree->get_next(pNode->key);
      return *this;
    }

    iterator &operator++(int) { return operator++(); }

    iterator &operator--() {
      pNode = tree->get_prev(pNode->key);
      if (pNode == tree->get_begin_node()) assert(false);
      return *this;
    }

    iterator &operator--(int) { return operator--(); }

    bool operator==(const iterator &b) const { return pNode == b.pNode; }

    bool operator!=(const iterator &b) const { return !operator==(b); }

    const KEY &operator*() const { return pNode->key; }

    iterator(node *n, const set<KEY, _compare> *t) : pNode(n), tree(t) {}
  };

  typedef iterator const_iterator;

  iterator lower_bound(KEY key) {
    return iterator(lower_bound(root, key), this);
  }
  const_iterator lower_bound(KEY key) const {
    return const_iterator(lower_bound(root, key), this);
  }

  iterator upper_bound(KEY key) { return iterator(get_next(key), this); }
  const_iterator upper_bound(KEY key) const {
    return const_iterator(get_next(key), this);
  }

  iterator end() { return iterator(right_end_node, this); }
  const_iterator end() const { return const_iterator(right_end_node, this); }

  const_iterator cend() const { return const_iterator(right_end_node, this); }

  iterator begin() {
    node *p = root;
    while (p->left != left_end_node) p = p->left;
    return iterator(p, this);
  }

  const_iterator begin() const {
    node *p = root;
    while (p->left != left_end_node) p = p->left;
    return const_iterator(p, this);
  }

  const_iterator cbegin() const {
    node *p = root;
    while (p->left != left_end_node) p = p->left;
    return const_iterator(p, this);
  }

  iterator find(const KEY &key) { return iterator(find_key(key), this); }
  const_iterator find(const KEY &key) const {
    return const_iterator(find_key(key), this);
  }
};

template <class KEY, class _compare>
_compare set<KEY, _compare>::CMP = _compare();
#endif