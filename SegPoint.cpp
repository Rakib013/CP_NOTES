struct node{
  node(){}
};
 
struct segPoint{
  vector<node> tr;
  vector<int> a;
  segPoint(int N) {
    tr.resize(4 * N);
    a.resize(N);
  }

  node merge(node &res, node &l, node &r) {
    return res;
  }

  void build (int u, int s, int e) {
    if (s == e) {
      return;
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    build(v, s, m);
    build(w, m + 1, e);
    merge(tr[u], tr[v], tr[w]);
  }

  void update(int point, int val, int u, int s, int e){
    if(e < point || s > point)return;
    if(s == e){
      return;
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    update(point, val, v, s, m);
    update(point, val, w, m + 1, e);
    merge(tr[u], tr[v], tr[w]);
  }

  auto query(int l, int r, int u, int s, int e){
    if(e < l || s > r)return node();
    if(s >= l && e <= r){
      return tr[u];
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    auto left = query(l, r, v, s, m);
    auto right = query(l, r, w, m + 1, e);
    auto ret = node();
    merge(ret, left, right);
    return ret;
  }
};