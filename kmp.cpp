vector<int> get_pi(vector<int> &s){
  int n = s.size();
  vector<int> pi(n);
  for (int k = 0, i = 1; i < n; ++i){
    if(s[i] == s[k]) {
      pi[i] = ++k;
    }
    else if(k == 0) {
      pi[i] = 0;
    }
    else {
      k = pi[k-1], --i;
    }
  }
  return pi;
}

vector nxt(v.size() + 5, vector (26, 0));
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < 26; j++) {
      int p = i;
      while (v[p] - 'A' != j) {
        if (p == 0) break;
        p = pi[p - 1];
      }
      if (v[p] - 'A' == j) nxt[i][j] = p + 1;
    }
  }
