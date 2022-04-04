#define n 1000000

const int NODE_N = 4 * n;

int arr[n];

struct node {
  int val;
  int l, r;
  int lazy;
} tree[NODE_N];

void build(int i, int l, int r) {
  if (l == r) {
    tree[i].val = arr[l];
    tree[i].l = tree[i].r = l;
    return;
  }
  int mi = (r - l) / 2 + l;
  build(i * 2, l, mi);
  build(i * 2 + 1, mi + 1, r);
  tree[i].val = tree[i * 2].val + tree[i * 2 + 1].val;
  tree[i].l = l;
  tree[i].r = r;
  tree[i].lazy = 0;
}

void push_down(int i) {
  tree[i * 2].lazy += tree[i].lazy;
  tree[i * 2].val += tree[i].lazy * (tree[i * 2].r - tree[i * 2].l + 1);
  tree[i * 2 + 1].lazy += tree[i].lazy;
  tree[i * 2 + 1].val +=
      tree[i].lazy * (tree[i * 2 + 1].r - tree[i * 2 + 1].l + 1);
  tree[i].lazy = 0;
}

void update(int i, int l, int r, int delta) {
  if (l <= tree[i].l && tree[i].r <= r) {
    tree[i].val += delta * (tree[i].r - tree[i].l + 1);
    tree[i].lazy += delta;
    return;
  }
  if (tree[i].l != tree[i].r) push_down(i);
  int mi = (tree[i].l + tree[i].r)/2;
  if(l <= mi) update(i*2, l, r, delta);
  if(mi + 1 <= r) update(i*2+1, l, r, delta);
  tree[i].val = tree[i*2].val + tree[i*2+1].val;
}

int query(int i, int l, int r) {
  if(l <= tree[i].l && tree[i].r <= r) return tree[i].val;
  if(tree[i].l != tree[i].r) push_down(i);
  int ans = 0, mi = (tree[i].l + tree[i].r)/2;
  if(l <= mi) ans += query(i*2, l, r);
  if(mi + 1 <= r) ans += query(i*2+1, l, r);
  return ans;
}