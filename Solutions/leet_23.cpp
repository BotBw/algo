#include "bits/stdc++.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  using pii = pair<int, int>;
  ListNode* mergeKLists(vector<ListNode*>& a) {
    ListNode dump;
    ListNode* p = &dump;
    int n = a.size();
    priority_queue<pii, vector<pii>, greater<pii>> q;
    FOR(i, 0, n - 1) {
      if (a[i]) q.push({a[i]->val, i});
    }
    while (q.size()) {
      auto cur = q.top();
      q.pop();
      int i = cur.second;
      p->next = a[i];
      p = p->next;
      a[i] = a[i]->next;
      if (a[i]) q.push({a[i]->val, i});
    }
    return dump.next;
  }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}