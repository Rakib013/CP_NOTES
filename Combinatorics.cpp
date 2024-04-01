ll paw(ll a, ll b){
    ll res = 1;
    while(b){
        if(b % 2 == 1){
            (res *= a) %= mod;
        }
        (a *= a) %= mod;
        b /= 2;
    }
    return res;
}
 
struct comb{
    vector<ll> fact, inv;
    int n;
    comb(int _n){
        n = _n;
        fact.assign(n, 0);
        inv.assign(n, 0);
        fact[0] = 1;
        for(int i=1; i<n; i++){
            (fact[i] = fact[i-1] * i) %= mod;
        }
        inv[n-1] = paw(fact[n-1], mod-2);
        for(int i=n-2; i>=0; i--){
            (inv[i] = inv[i+1] * (i+1)) %= mod;
        }
    }
 
    ll ncr(ll n, ll r){
        if(n == r)return 1;
        if(n < r)return 0;
        return ((fact[n] * inv[r])%mod * inv[n-r])%mod;
    }
};