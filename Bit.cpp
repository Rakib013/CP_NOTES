struct BIT{
    int n;
    vector<ll> bit;
    BIT(int _n){
        n = _n + 1;
        bit.assign(n, 0);
    }
 
    void update(int idx, int val){
        for(idx; idx<=n; idx += idx & (-idx)){
            bit[idx] += val;
        }
    }
 
    void update(int l, int r, int val){
        update(r+1, -val);
        update(l, val);
    }
 
    ll get(int idx){
        ll res = 0;
        while(idx > 0){
            res += bit[idx];
            idx -= idx & (-idx);
        }
        return res;
    }
 
    ll get(int l, int r){
        return get(r) - get(l-1);
    }
};