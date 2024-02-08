#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class sqrt_decompotion{
  vector<ll> ar;
  vector<ll> blocks;
  ll size;
  ll sq;
public:
  void build(vector<ll> v){
    ar=v;
    blocks.resize( sqrt( v.size() ) + 1);
    size=blocks.size();
    sq=size-1;
    ll block_id = -1;
    for(ll i=0;i<v.size();i++){
      //figure out block of index
      if(i % sq == 0)
        block_id++;
      blocks[block_id] += v[i];
    }

  }

  ll query(ll l,ll r){
    ll ans=0;
    //travese till left
    for(ll i=l;i<=r;){
      if(i % sq ==0 && i+sq-1 <= r){
        ans+=blocks[i/sq];
        i+=sq;
      }
      else{
        ans+=ar[i];
        i++;
      }
    }
    return ans;
  }

};

int main(){
  sqrt_decompotion obj;
  vector<ll> v={1,2,3,4,5,6,7,8};
  obj.build(v);
  cout<<obj.query(0,2);
  
}
