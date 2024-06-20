set<array<int, 2>> s;
vector<int> tin(n, 0), low(n, 0), vis(n, 0);
int T = 1;
auto dfs = [&](auto self, int u, int pr)->void{
    vis[u] = 1;
    tin[u] = low[u] = T++;
    for(auto v:adj[u])if( v!= pr){
        if(vis[v]){
            low[u] = min(tin[v], low[u]);
        }else{
            self(self, v, u);
            low[u] = min(low[u], low[v]);
            if(tin[u] < low[v]){
                s.insert({u, v});
                s.insert({v, u});
            }
        }
    }
};
dfs(dfs, 0, 0);

vector<int> p(n), sz(n, 1);
iota(p.begin(), p.end(), 0);

auto find = [&](auto self, int x){
    if(p[x] == x)return x;
    return p[x] = self(self, p[x]);
};

auto marge = [&](auto self, int a, int b){
    a = find(find, a);
    b = find(find, b);
    if(a == b)return 0;
    if(sz[a] < sz[b])swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return 1;
};

for(int i=0; i<n; i++){
    for(auto v:adj[i]){
        if(!s.count({i, v})){
            marge(marge, i, v);
        }
    }
}

vector<vector<int>> G(n);
for(int i=0; i<n; i++){
    for(auto v:adj[i])if(s.count({i, v})){
        G[find(find, i)].push_back(find(find, v));
        G[find(find, v)].push_back(find(find, i));
    }
}