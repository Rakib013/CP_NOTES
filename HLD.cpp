const int N = 2e5 + 5;
int n, q, k = 1 << 19;
vector<int> a(N), st(k);
vector<int> adj[N];
vector<int> sz(N, 0), dep(N, 0), head(N, -1), hvc(N, -1), tin(N, 0), had(N, -1), par(N, 0);
 
void update(int idx, int val) {
	st[idx += n] = val;
	for (idx /= 2; idx; idx /= 2) st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}
 
int query(int lo, int hi) {
	int ra = 0, rb = 0;
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = max(ra, st[lo++]);
		if (hi & 1) rb = max(rb, st[--hi]);
	}
	return max(ra, rb);
}
 
void dfs(int u, int pr) {
    sz[u] = 1;
    par[u] = pr;
    for(auto v:adj[u])if(v ^ pr){
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if(hvc[u] == -1 || sz[hvc[u]] < sz[v]){
            hvc[u] = v;
        }
    }
}

int T = 0;
void HLD(int u, int pr, int hed){
    tin[u] = T++;
    had[u] = hed;
    if(hvc[u] != -1){
        HLD(hvc[u], u, hed);
    }
    for(auto v:adj[u])if(v ^ pr && v ^ hvc[u]){
        HLD(v, u, v);
    }
};
 
int path_query(int a, int b){
    int res = 0;
    while(had[a] != had[b]){
        if(dep[had[a]] < dep[had[b]]){
            swap(a, b);
        }
        res = max(res, query(tin[had[a]] + 1, tin[a] + 1));
        a = par[had[a]];
    }
    if(dep[a] > dep[b]){
        swap(a, b);
    }
    return max(res, query(tin[a] + 1, tin[b] + 1));
}  

// In the main
dfs(0, 0);
HLD(0, -1, 0);

for(int i=0; i<n; i++){
    update(tin[i] + 1, a[i]);
}