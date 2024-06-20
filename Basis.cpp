struct Basis {
  int LG;
  vector<int> a;
  Basis (int b) {
    LG = b;
    a.resize(LG);
  }
  void clear () {
    for (int i = 0; i < LG; i++) a[i] = 0;
  }
  int reduce (int x) {
    for (int i = LG - 1; i >= 0; i--) {
      if (x & (1 << i)) {
        x ^= a[i];
      }
    }
    return x;
  }
  bool insert (int x) {
    x = reduce(x);
    if (x == 0) false;
    for (int i = LG - 1; i >= 0; i--) {
      if (x & (1 << i)) {
        a[i] = x;
        break;
      }
    }
    return true;
  }
};