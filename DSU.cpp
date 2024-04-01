struct DSU{
    vector<int> p, sz;
    DSU(int n):p(n), sz(n, 1){
        iota(p.begin(), p.end(), 0);
    }
 
    int find(int x){
        if(x == p[x])return x;
        return p[x] = find(p[x]);
    }
 
    bool marge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b)return false;
        if(sz[a] < sz[b])swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};