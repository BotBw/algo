#define LOCAL
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
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        ListNode *p = head;
        while(p) {
          a.push_back(p->val);
          p = p->next;
        }
        int l = 0, r = (int)a.size() - 1;
        while(l < r) {
          if(a[l] != a[r]) return false;
          l++, r--;
        }
        return true;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}