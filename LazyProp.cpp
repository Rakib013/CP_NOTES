struct node{
  int lazy;
  node() {
    lazy = 0;
  }
};
 
struct seglazy{
  vector<node> tr;
  vector<int> a;
  seglazy (int N) {
    tr.resize(4 * N);
    a.resize(N);
  }
  node merge (node &res, node &l, node &r) {
    node res;
    return res;
  }
  void push_down(int cur, int child) {
    if (tr[cur].lazy) {
      tr[child].lazy = tr[cur].lazy;
    }
  }
  void push(int u, int l, int r){
    if (l != r) {
      // Push down the current value
      int v = u << 1;
      push_down(u, v);
      push_down(u, v | 1);
    }
    // Add current value to the current node
    if (tr[u].lazy != 0) {}
    // Clear the currect lazy value
    tr[u].lazy = 0;
  }
  void build (int u, int s, int e) {
    if (s == e) {
      // Build the tree
      return;
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    build(v, s, m);
    build(w, m + 1, e);
    merge(tr[u], tr[v], tr[w]);
  }
  void update(int l, int r, int val, int u, int s, int e) {
    push(u, s, e);
    if(e < l || s > r)return;
    if(s >= l && e <= r){
      // Update lazy here
      push(u, s, e);
      return;
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    update(l, r, val, v, s, m);
    update(l, r, val, w, m + 1, e);
    merge(tr[u], tr[v], tr[w]);
  }
  void update(int p, int u, int s, int e) {
    push(u, s, e);
    if (e < p || s > p) return;
    if (s == e) {
      // Point update
      return;
    }
    int v = u << 1, w = v | 1, m = (s + e) >> 1;
    update(p, v, s, m);
    update(p, w, m + 1, e);
    merge(tr[u], tr[v], tr[w]);
  }
  auto query(int l, int r, int u, int s, int e){
    push(u, s, e);
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