#include <bits/stdc++.h>
using namespace std;


int main(){
  long long int n,sum=0,mid=0;
  cin>>n;
  vector<long long int> a,b;
  sum=(n*(n+1))/2;
  if(sum%2==0){
    cout<<"YES"<<endl;
    mid=sum/2;
    long long int ptr=n;
    while(mid!=0 && ptr!=0){
      if(ptr<=mid){
        a.push_back(ptr);
        mid=mid-ptr;
      }

      else{
        b.push_back(ptr);
      }
      ptr--;
    }

    if(ptr!=0){
      while(ptr){
        b.push_back(ptr);
        ptr--;
      }
    }

    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++){
      cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<b.size()<<endl;
    for(int i=0;i<b.size();i++){
      cout<<b[i]<<" ";
    }
  }

  else{
    cout<<"NO";
  }
  
}
