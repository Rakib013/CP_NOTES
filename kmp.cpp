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