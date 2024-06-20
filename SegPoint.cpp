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

  node merge(node l, node r){
    node res;
    // Merger the nodes
    return res;
  }

  void build (int u, int s, int e) {
    if (s == e) {
      return;
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    build(v, s, m);
    build(w, m + 1, e);
    tr[u] = merge(tr[v], tr[w]);
  }

  void update(int point, int val, int u, int s, int e){
    if(e < point || s > point)return;
    if(s == e){
      return;
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    update(point, val, v, s, m);
    update(point, val, w, m + 1, e);
    tr[u] = merge(tr[v], tr[w]);
  }

  auto query(int l, int r, int u, int s, int e){
    if(e < l || s > r)return node();
    if(s >= l && e <= r){
      return tr[u];
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    auto left = query(l, r, v, s, m);
    auto right = query(l, r, w, m + 1, e);
    return merge(left, right);
  }
};