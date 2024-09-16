struct Trie {
  struct node {
    node* ch[2];
    int cnt;

    node() {
      cnt = 0;
      ch[0] = nullptr;
      ch[1] = nullptr;
    }

    node* next(int b) {
      if (!ch[b]) ch[b] = new node;
      return ch[b];
    }
  } *root;
  
  Trie () {
    root = new node;
  }

  void ins(int x) {
    node* targ = root;
    for (int i = 29; i >= 0; --i) {
      int v = !!(x & (1 << i));
      targ = targ->next(v);
      ++targ->cnt;
    }
  }

  void del(int x) {
    node* targ = root;
    for (int i = 29; i >= 0; --i) {
      int v = !!(x & (1 << i));
      targ = targ->next(v);
      --targ->cnt;
    }
  }

  int mx_xor(int x) {
    node* tar = root;
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
      int v = !!(x & (1 << i));
      if (tar -> next(!v) -> cnt > 0) {
        tar = tar -> next(!v);
        ans |= (1 << i);
      } else {
        tar = tar -> next(v);
      }
    }
    return max(ans, x);
  }
};