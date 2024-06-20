const int N = 1e5 + 5;

//SegMentTreeLazy:
struct node{
    // decalre variables
    node(){
        // Initialize the variable
    }
};
 
struct seglazy{
    vector<node> tr;
    vector<int> a, laz;
    seglazy() {
        tr.resize(4 * N);
        laz.assign(4 * N, 0);
        a.resize(N);
    }
    node merge(node l, node r){
        node res;
        // merge left child with right child
        return res;
    }
    void push_down(int cur, int child){
        // Push down from parent
    }
    void push(int u, int l, int r){
        if (l != r) {
            // Push down the current value
        }
        // Add current value to the current node

        // Clear the currect lazy value
    }
    void build (int u, int s, int e) {
        if (s == e) {
            // Do something
            return;
        }
        int v = u << 1, w = v | 1, m = (s + e) >> 1;
        build(v, s, m);
        build(w, m + 1, e);
        tr[u] = merge(tr[v], tr[w]);
    }
    void update(int l, int r, int val, int u, int s, int e){
        push(u, s, e);
        if(e < l || s > r)return;
        if(s >= l && e <= r){
            // Update at the lazy array
            push(u, s, e);
            return;
        }
        int v = u << 1, w = v | 1, m = (s + e) >> 1;
        update(l, r, val, v, s, m);
        update(l, r, val, w, m + 1, e);
        tr[u] = merge(tr[v], tr[w]);
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
        return merge(left, right);
    }
};