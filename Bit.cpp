struct Fenwick{
  int n;
  vector<long long> bit;
  Fenwick(int _n){
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

  long long get(int idx){
    long long res = 0;
    while(idx > 0){
      res += bit[idx];
      idx -= idx & (-idx);
    }
    return res;
  }

  long long get(int l, int r){
    return get(r) - get(l-1);
  }
};