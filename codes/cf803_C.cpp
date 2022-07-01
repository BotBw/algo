#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) \
  assert((a) >= (b)); \
  for (int i = (a); i >= (b); --i)

int n;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<int> nums;
    bool flag = true;
    FOR(i, 1, n) {
      int a;
      scanf("%d", &a);
      int poscnt = 0, negcnt = 0, zerocnt = 0;
      if (a == 0 && zerocnt < 2) {
        zerocnt++;
        nums.push_back(a);
      } else if (a > 0)
        nums.push_back(a), poscnt++;
      else
        nums.push_back(a), negcnt++;
      if (poscnt > 2 || negcnt > 2) {
        flag = false;
        break;
      }
    }
    int sz = nums.size();
    if (!flag) goto bad;

    FOR(i, 0, sz - 1) {
      FOR(j, i + 1, sz - 1) {
        FOR(k, j + 1, sz - 1) {
          int sum = nums[i] + nums[j] + nums[k];
          bool flag = false;
          FOR(z, 1, sz - 1) {
            if (nums[z] == sum) {
              flag = true;
              break;
            }
          }
          if (!flag) {
            goto bad;
          }
        }
      }
    }
    printf("YES\n");
    continue;
  bad:
    printf("NO\n");
  }
}