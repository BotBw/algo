#include "bits/stdc++.h"

class Solution {
public:
    struct tag_mx {
      int mx_val;
    };
    static void push_up(tag_mx &a, const tag_mx &b, const tag_mx& c) {
      a.mx_val = max(b.mx_val, c.mx_val);
    } 
    static void push_down(tag_mx &a, tag_mx &b, int l1, tag_mx &c, int l2) {
      return;
    }
    static tag_mx ie_tagmx() {
      return {0};
    }
    struct tag_sum {
      ll sum;
    };
    static void push_up1(tag_sum &a, const tag_sum &b, const tag_sum& c) {
      a.sum = b.sum + c.sum;
    } 
    static void push_down1(tag_sum &a, tag_sum &b, int l1, tag_sum &c, int l2) {
      return;
    }
    static tag_sum ie_sum() {
      return {0};
    }
    int maximumRobots(vector<int>& maxC, vector<int>& sumC, long long budget) {
        int n = maxC.size();
        vector<tag_mx> init1(n);
        vector<tag_sum> init2(n);
        FOR(i, 0, n-1) {
          init1[i].mx_val = maxC[i];
          init2[i].sum = sumC[i];
        }
        int res = 0;
        segtree<tag_mx, push_up, push_down, ie_tagmx> seg1(0, n-1, init1);
        segtree<tag_sum, push_up1, push_down1, ie_sum> seg2(0, n-1, init2);
        for(int l = 0, r = 0; r < n; r++) {
          while(l <= r) {
            ll cur = seg1.query(l, r).mx_val + (ll)(r - l + 1) * seg2.query(l, r).sum;
            if(cur <= budget) break;
            l++;
          }
          res = max(res, r - l + 1);
        }
        return res;
    }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}