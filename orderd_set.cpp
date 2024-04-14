// @rakibul-Islam 

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

// Multiset
bool exist(ordered_set &s, long long x){
  if((s.upper_bound(x))==s.end()){
    return 0;
  }
  return ((*s.upper_bound(x))==x);
}

// Multiset
void erase(ordered_set &s, long long x) {
  if(exist(s,x)){
    s.erase(s.upper_bound(x));
  }
}