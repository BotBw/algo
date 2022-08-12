#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

// if debugging codes are contained, delete this line before submitting
#define DEBUG

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
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode dumpOdd, dumpEven;
        ListNode *i = &dumpOdd, *j = &dumpEven, *p = head;
        int c = 0;
        while(p) {
            if(c%2 == 0) {
                i->next = p;
                i = i->next;
            } else {
                j->next = p;
                j = j->next;
            }
            c++;
            p = p->next;
        }
        i->next  = dumpEven.next;
        j->next = nullptr;
        head = dumpOdd.next;
        return head;
    }
};