#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
class segment_tree_min{
  ll size;
  vector<ll> st;
public:
  segment_tree_min(ll t){
    size=t;
    st.resize(4*t);
  }

  void print_st(){
    for(ll i=0;i<st.size();i++){
      cout<<st[i]<<" ";
    }
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

    st[node]=min(st[node*2],st[node*2+1]);

  }

  ll query(ll l,ll r,ll start,ll end,ll node){
    //no overlap
    if(r<start || l>end){
      return LLONG_MAX;
    } 

    //total overlap 
    if(l>=start && r<=end){ 
      return st[node];
    }

    //partial overlap
    ll mid=(start+mid)/2;
    ll q1=query(l,r,start,mid,node*2);
    ll q2=query(l,r,mid+1,end,node*2+1);
    return min(q1,q2);
  }

  ll query(ll l,ll r){
    return query(l,r,0,size-1,1);
  }
};



int main(){
  vector<ll>  v{2,1,5,9,3,4,2,8};
  segment_tree_min st(v.size());
  st.build(v);
  cout<<st.query(0,5);
}
