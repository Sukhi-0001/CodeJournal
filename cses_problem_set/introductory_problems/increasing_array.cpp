#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  long long int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  long long int count=0;
  for(int i=1;i<n;i++){
    long long int prev=arr[i-1];
    long long int curr=arr[i];
    if(curr<prev){
      count+=prev-curr;
      arr[i]=prev;
    }
  }
  cout<<count;
}
