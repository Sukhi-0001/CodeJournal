#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  if(n==1){
    cout<<"1";
    return 0;
  }
  if(n<=3){
    cout<<"NO SOLUTION";
    return 0;
  }
  // print even no
  long long i=2;
  while(i<=n){
    cout<<i<<" ";
    i+=2;
  }
  i=1;
  while(i<=n){
    cout<<i<<" ";
    i+=2;
  }
}
