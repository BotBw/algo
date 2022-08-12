class dsu {
 public:
  std::vector<int> p;
  std::vector<int> sz;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    sz = std::vector<int>(n, 1);
    std::iota(p.begin(), p.end(), 0);
  }

  inline int find(int x) {
    return (x == p[x] ? x : (p[x] = find(p[x])));
  }

  inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
