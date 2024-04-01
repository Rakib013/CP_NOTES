vector<int> stk, l(n, -1), r(n, -1);

for (int i = 0; i < n; i++) {
    while (!stk.empty() && a[i] < a[stk.back()]) {
        int x = stk.back();
        stk.pop_back();
        r[x] = i;
    }

    if (!stk.empty()) {
        l[i] = stk.back();
    }
    stk.push_back(i);
}