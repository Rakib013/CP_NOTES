const int MAX = 2e5 + 5;

vector<long long> MOD = {
  127657753, 987654319, 
  1000000007, 1000000009, 
  999993721, 999993733, 
  999996043, 999997643, 
  999999937, 999999667, 
  999999937, 1000000021
};
vector<array<long long, 2>> pw(MAX), ipw(MAX);
array<long long, 2> bs = {137, 277};

long long paw(long long a, long long b, int t) {
  long long res = 1;
  while (b) {
    if (b & 1LL) {
      (res *= a) %= MOD[t];
    }
    (a *= a) %= MOD[t];
    b /= 2;
  }
  return res;
}

void pre() {
  pw[0][0] = pw[0][1] = 1;
  for (int i = 1; i < MAX; i++) {
    (pw[i][0] = pw[i - 1][0] * bs[0]) %= MOD[0];
    (pw[i][1] = pw[i - 1][1] * bs[1]) %= MOD[1];
  }
  ipw[0][0] = ipw[0][1] = 1;
  long long ip1 = paw(bs[0], MOD[0] - 2, 0);
  long long ip2 = paw(bs[1], MOD[1] - 2, 1);
  for (int i = 1; i < MAX; i++) {
    ipw[i][0] = (ipw[i - 1][0] * ip1) % MOD[0];
    ipw[i][1] = (ipw[i - 1][1] * ip2) % MOD[1];
  }
}

struct Hashing {
  int n;
  string s;
  vector<array<long long, 2>> hs;
  Hashing (string t) {
    n = t.size();
    s = t;
    hs.resize(n + 1);
    for (int i = 0; i < n; i++) {
      (hs[i + 1][0] = hs[i][0] + (pw[i][0] * s[i]) % MOD[0]) %= MOD[0];
      (hs[i + 1][1] = hs[i][1] + (pw[i][1] * s[i]) % MOD[1]) %= MOD[1];
    }
  }
  array<long long, 2> get_hash(int l, int r) {
    if (l > r) return {0, 0};
    long long res1 = ((hs[r][0] - hs[l - 1][0]) + MOD[0]) % MOD[0];
    long long res2 = ((hs[r][1] - hs[l - 1][1]) + MOD[1]) % MOD[1];
    (res1 *= ipw[l - 1][0]) %= MOD[0];
    (res2 *= ipw[l - 1][1]) %= MOD[1];
    return {res1, res2};
  }
};
