#ifdef maxV
#ifdef maxE
int head[maxV], cnt;

struct edge {
  int u, v, w, next;
} e[maxE];

void addE(int u, int v, int w) {
  e[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}
#endif
#endif