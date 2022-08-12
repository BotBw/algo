#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 1e4 + 5;
const int maxCapacity = 1e7 + 5;

int n, capacity;

struct obj {
  int w, p;
} objs[maxN];

ll P[maxCapacity];
// i: item index, j: capacity
// if don't buy i-th item, the answer will be the same as only considerring (i-1)th item
// at the same capacity
//
// if you buy one i-th item, the answer will be the same as considering buy i-the item
// at less capacity (which is j - obj[i].w)
// P[i, j] = max(P[i - 1, j], P[i, j - objs[i].w] + objs[i].p)
//
// P[i, j] only references P[i-1, j] and P[i, j - objs[i].w]
// thus can be compressed into 1-dimension array P[capacity] (no need i-2, i-3 ...)
// and we need to iterate forward. (always reference to less capacity at i-th item)

void completeKnapsack(int obj_id) {
  for(int j = objs[obj_id].w; j <= capacity; j++) {
    P[j] = max(P[j], P[j - objs[obj_id].w] + objs[obj_id].p);
  }
}

int main() {
  cin >> capacity >> n;
  for (int i = 1; i <= n; i++)
    cin >> objs[i].w >> objs[i].p;
  for(int i = 1; i <= n; i++) {
    completeKnapsack(i);
  }
  cout << P[capacity];
  return 0;
}