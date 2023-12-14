#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main (int argc, char *argv[]) {
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll> a(n),b(m);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  for(ll i=0;i<m;i++){
    cin>>b[i];
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll count=0;
  ll ptr1=0,ptr2=0;
  while(ptr1<n && ptr2<m){
    if(b[ptr2]<a[ptr1]-k){
      ptr2++;
    }

    else if(b[ptr2]>a[ptr1]+k){
      ptr1++;
    }
    else{
      ptr1++;
      ptr2++;
      count++;
    }
  }

  cout<<count;



  return 0;
}
