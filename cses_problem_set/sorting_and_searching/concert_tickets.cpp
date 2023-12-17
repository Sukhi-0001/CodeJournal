#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
  ll n,m;
  cin>>n;
  cin>>m;
  multiset<ll> ms;
  ll temp;
  for(ll i=0;i<n;i++){
    cin>>temp;
    ms.insert(temp);
  }
  for(ll i=0;i<m;i++){
    cin>>temp;
    multiset<ll> :: iterator it;
    it=ms.upper_bound(temp);
    if(it==ms.begin()){
      cout<<"-1"<<endl;
    }

    else{
      cout<<*(--it)<<endl;
      ms.erase(it);
    }
  }
}
