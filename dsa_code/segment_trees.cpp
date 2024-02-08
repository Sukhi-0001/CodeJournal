#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
class segment_tree_min{
  ll size;
  vector<ll> lazy;
  vector<ll> st;
public:
  segment_tree_min(ll t){
    size=t;
    lazy.resize(4*t,0);
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
    if(lazy[node]!=0){
      st[node]+=lazy[node];
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
      lazy[node]=0;
    }
    //no overlap
    if(l>end || r<start){
      return LLONG_MAX;
    }

    //total overlap
    if(start>=l && end<=r){
      return st[node];
    }

    //partial overlap
    ll mid=(start+end)/2;
    ll q1=query(l,r,start,mid,node*2);
    ll q2=query(l,r,mid+1,end,node*2+1);
    return st[node]=min(q1,q2);
  }

  ll query(ll l,ll r){
    return query(l,r,0,size-1,1);
  }

  void update(ll l,ll r,ll val,ll s,ll e,ll node){
    //no overlap
    if(l>e || r<s){
      return;
    }
    //complete overlap
    if(l>=s && r<=e){
      lazy[node*2]+=val;
      lazy[node*2+1]+=val;
      st[node]+=val;
      return;
    }
    //partial overlap
    ll mid=(s+e)/2;
    update(l,r,val,s,mid,node*2);
    update(l,r,val,mid+1,e,node*2+1);
    st[node]=min(st[node*2],st[node*2+1]);
  }

  void update(ll l,ll r,ll val){
    update(l,r,val,0,size-1,1);
  }

  void update(ll pos,ll val,ll start,ll end,ll node){
    if(start==end){
        st[node]=val;
      return;
    }
    ll mid=(start+end)/2;
    if(pos<=mid)
      update(pos,val,start,mid,node*2);
    else
      update(pos,val,mid+1,end,node*2+1);
    st[node]=min(st[node*2],st[node*2+1]);
  }

  void update(ll pos,ll val){
    update(pos,val,0,size-1,1);

  }
};



int main(){
  vector<ll>  v{1,2,3,4,5,6,7,8};
  segment_tree_min st(v.size());
  st.build(v);
  st.update(0,5,1);
  cout<<st.query(0,5);
}
