#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
class fenwick_tree{
  vector<ll> ft;
  public:
  
  void build(vector<ll> v){
    ft.resize(v.size()+1,0);
    for(ll i=0;i<v.size();i++){
      update(i+1,v[i]);
    }

  }

  ll sum(ll index){
    ll ans=0;
    while(index){
      ans+=ft[index];
      index -= index & (-index);
    }
    return ans;
  }

  void update(ll index,ll val){
    while(index<ft.size()){
      ft[index]+=val;
      //get right most bit
      index += index & (-index);
    }
  }
};

int main(){
  fenwick_tree obj;
  vector<ll> v{1,2,3,4,5,6,7,8};
  obj.build(v);
  cout<<"hello";
  cout<<obj.sum(4);
}
