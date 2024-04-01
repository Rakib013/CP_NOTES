struct Node{
    Node *next[2];
    int cnt, end;
    Node(){
        fill(next, next+2, nullptr);
        cnt = end = 0;
    }
};
 
struct Trie{
    Node *root;
 
    Trie(){
        root = new Node();
    }
 
    void insert(int val){
        Node *start = root;
        for(int i=30; i>=0; i--){
            if(val & (1<<i)){
                if(start->next[1] == NULL){
                    start->next[1] = new Node();
                }
                start = start->next[1];
            }else{
                if(start->next[0] == NULL){
                    start->next[0] = new Node();
                }
                start = start->next[0];
            }
            start->cnt++;
        }
    }
 
    void remove(int val){
        Node *start = root;
        for(int i=30; i>=0; i--){
            if(val & (1<<i)){
                start = start->next[1];
            }else{
                start = start->next[0];
            }
            start->cnt--;
        }  
    }
};