vector tin(n, 0), tout(n, 0), hvc(n, -1), sz(n, 0), ans(q, -1);
vector<int> euler;
auto dfs = [&](auto self, int u, int pr) -> void {
    sz[u] = 1;
    tin[u] = euler.size();
    euler.push_back(u);
    for (auto v:adj[u]) if (v ^ pr) {
        self(self, v, u);
        sz[u] += sz[v];
        if (hvc[u] == -1 || sz[hvc[u]] < sz[v]) {
        hvc[u] = v;
        }
    }
    tout[u] = euler.size() - 1;
};

auto add = [&](int u) -> void {
    for (int v = tin[u]; v <= tout[u]; v++) {
        //
    }
};

auto dsu = [&](auto self, int u, int pr, int keep) -> void {
    for (auto v:adj[u]) if (v != pr && hvc[u] != v) {
        self(self, v, u, 0);
    }
    if (hvc[u] != -1) {
        self(self, hvc[u], u, 1);
    }
    for (auto v:adj[u]) if (v != pr && v != hvc[u]) {
        add(v);
    }
    for (auto x:qr[u][1]) {
        hole.insert(x);
    }
    if (!keep) {
        //
    }
};
dfs(dfs, 0, 0);
dsu(dsu, 0, 0, 0);