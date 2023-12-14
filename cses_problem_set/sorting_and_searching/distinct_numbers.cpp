#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  vector<long long int > v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }

  sort(v.begin(),v.end());
  long long int prev=0,curr=1,count=0;
  for(;curr<n;curr++){
    if(v[prev]!=v[curr])
      count++;
    prev=curr;
  }
  cout<<count+1;
}
