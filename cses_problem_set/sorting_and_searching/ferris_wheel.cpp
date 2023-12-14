#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main (int argc, char *argv[]) {
  ll n,x;
  cin>>n>>x;
  vector<ll> v(n);
  for(ll i=0;i<n;i++){
    cin>>v[i];
  }
  ll count=0;
  ll temp=0;
  sort(v.begin(),v.end());
  ll i=0,j=n-1;
  vector<int> have_gondola(n,0);
  while(i<j){
    if(v[i]+v[j]>x){
      j--;
    }
    else{
      count++;
      have_gondola[i]=have_gondola[j]=1;
      i++;
      j--;
    }
  }

  for(ll i=0;i<n;i++){
    count+=have_gondola[i]==0;
  }

  cout<<count;
  return 0;
}
