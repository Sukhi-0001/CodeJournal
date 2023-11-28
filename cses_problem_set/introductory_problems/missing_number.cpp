#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int a=0,n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int temp;
    cin>>temp;
    a+=temp;

  }
  n=(n*(n+1))/2;
  std::cout <<n-a<< std::endl;
}
