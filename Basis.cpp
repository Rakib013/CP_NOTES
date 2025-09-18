struct Basis {
  static const int D = 20;
  int b[D], sz;
  vector<int> idx;
 
  Basis() {
    memset(b, 0, sizeof b);
    sz = 0;
  }
 
  int size() {
    return sz;
  }
 
  bool add(int x, int j) {
    for (int i = D - 1; i >= 0; --i) {
      if (x >> i & 1 ^ 1) continue;
      if (!b[i]) {
        b[i] = x; idx.push_back(j); sz++;
        return true;
      }
      x ^= b[i];
    } return false;
  }
  void reduce(int &x) {
    for (int d = D - 1; d >= 0; --d) {
      x = min(x, x ^ b[d]);
    }
  }
  bool exists(int x) {
    return reduce(x), x == 0;
  }
  int max_xor(int x = 0) {
    for (int i = D - 1; i >= 0; --i) {
      x = max(x, x ^ b[i]);
    } return x;
  }
  int kth(int k) {
    int ret = 0, rem = sz;
    for (int i = D - 1; i >= 0; --i) {
      if (!b[i]) continue;
      rem--;
      if (ret >> i & 1) ret ^= b[i];
      if ((1 << rem) >= k) continue;
      ret ^= b[i]; k -= 1 << rem;
    } return ret;
  }
  int count_lt(int x) {
    int ans = 0, rem = sz, mask = 0;
    for (int i = D - 1; i >= 0; --i) {
      if (b[i]) {
        rem--;
        if (x >> i & 1) {
          ans += 1 << rem;
          mask = max(mask, mask ^ b[i]);
        }
        else {
          mask = min(mask, mask ^ b[i]);
        }
      }
      else {
        if ((x ^ mask) >> i & 1) {
          if (x >> i & 1) return ans + (1 << rem);
          return ans;
        }
      }
    }
    return ans;
  }
  int count_lte(int x) {
    return count_lt(x + 1);
  }
};
