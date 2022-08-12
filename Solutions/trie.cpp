#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

const int maxN = 1e5+5;

int node[maxN][26];
bool exist[maxN];
int cnt;

void insert(const char* str, int l) {
  int p = 0;
  FOR(i, 0, l-1) {
    int c = str[i]-'a';
    if(!node[p][c])
      node[p][c] = ++cnt;
    p = node[p][c];
  }
  exist[p] = 1;
}

bool query(const char* str, int l) {
  int p = 0;
  FOR(i, 0, l-1) {
    int c = str[i]-'a';
    if(!node[p][c]) return false;
    p = node[p][c];
  }
  return exist[p];
}

class Trie {
  struct node {
    node* child[26];
    bool exist;
  };
  node *root;
  const int sz = 1e5+5;
  Trie(){
    root = new node;
    for(int i = 0; i < 26; i++) root->child[i] = 0;
    root->exist = 0;
  }
  void insert(const char *str, int l) {
    node *p = root;
    for(int i = 0; i < l; i++) {
      int c = str[l]-'a';
      if(!p->child[c])
        p->child[c] = new node;
      p = p->child[c];
    }
    p->exist = 1;
  }
  bool query(const char *str, int l) {
    node *p = root;
    for(int i = 0; i < l; i++) {
      int c = str[l]-'a';
      if(!p->child[c]) return false;
      p = p->child[c];
    }
    return p->exist;
  }
  void deleteNodes(node *root) {
    if(!root) return;
    for(int i = 0; i < 26; i++) deleteNodes(root->child[i]);
    delete root;
  }
  ~Trie() {
    deleteNodes(root);
  }
};