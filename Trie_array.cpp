constexpr int N = 2e5 + 10;
const int BIT = 30;
int trie[N * BIT][2], cnt[N * BIT];
int node = 2;
 
void ins(int num) {
  int u = 1;
  for(int i = BIT - 1; i >= 0; --i) {
    int bit = (num >> i) & 1;
    if(!trie[u][bit]) trie[u][bit] = node++;

    u = trie[u][bit];
    cnt[u] += 1;
  }
}
 
void del(int num) {
  int u = 1;
  for(int i = BIT - 1; i >= 0; --i) {
    int bit = (num >> i) & 1;
    int nxt_node = trie[u][bit];
    if(--cnt[nxt_node] == 0) {
      trie[u][bit] = 0 ;
      return;
    }
    u = nxt_node;
  }
}
 
int mx_xor(int num) {
  int ans = 0, u = 1;
  for(int i = BIT - 1; i >= 0; --i) {
    int bit = (num >> i) & 1;
    int flip = bit ^ 1;
    if(trie[u][flip] and cnt[trie[u][flip]] > 0){
      ans  |= (1 << i);
      u = trie[u][flip];
    }
    else u = trie[u][bit];
  }
  return ans;
}
 
void clear() {
  for (int i = 1; i < node; ++i) {
      cnt[i] = 0;
      trie[i][0] = trie[i][1] = 0;
  }
  node = 2; 
}
