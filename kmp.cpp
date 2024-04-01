string s, t;    
cin>>s>>t;
 
int n = s.size(), m = t.size();
vector<int> pi(m);
for(int i=1, j = 0; i<m; ){
    if(t[i] == t[j]){
        j++;
        pi[i] = j;
        i++;
    }else{
        if(j)j = pi[j-1];
        else i++;
    }
}

int ans = 0;
for(int i=0, j=0; i<n; ){
    if(s[i] == t[j]){
        i++, j++;
    }else{
        if(j)j = pi[j-1];
        else i++;
    }
    if(j == m){
        ans++;
        j = pi[j-1];
    }
}
