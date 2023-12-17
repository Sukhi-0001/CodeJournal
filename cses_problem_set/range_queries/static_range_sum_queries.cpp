#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
class segment_tree_sum{
  ll size;
  vector<ll> st;
public:
  segment_tree_sum(ll t){
    size=t;
    st.resize(4*t);
  }

  void print_st(){
    for(ll i=0;i<st.size();i++){
      cout<<st[i]<<" ";
    }
    cout<<endl;
  }

  void build(vector<ll> v){
    build(0,v.size()-1,1,v); 
  }

  void build(ll start,ll end,ll node,vector<ll> &v){
    if(start==end){
      st[node]=v[start];
      return;
    }
    ll mid=(start+end)/2;

    build(start,mid,node*2,v);
    build(mid+1,end,node*2+1,v);

    st[node]=st[node*2]+st[node*2+1];

  }

  ll query(ll l,ll r,ll start,ll end,ll node){
    //no overlap
    if(r<start || l>end){
      return 0;
    } 

    //total overlap 
    if(start>=l && end<=r){ 
      return st[node];
    }

    //partial overlap
    ll mid=(start+end)/2;
    ll q1=query(l,r,start,mid,node*2);
    ll q2=query(l,r,mid+1,end,node*2+1);
    return q1+q2;
  }

  ll query(ll l,ll r){
    return query(l,r,0,size-1,1);
  }
};



int main(){
  ll n,q;
  cin>>n>>q;
  vector<ll> v(n);
  for(ll i=0;i<n;i++){
    cin>>v[i];
  }
  segment_tree_sum st(v.size());
  st.build(v);
  for(ll i=0;i<q;i++){
    ll a,b;
    cin>>a>>b;
    cout<<st.query(a-1,b-1)<<endl;
  }
}
