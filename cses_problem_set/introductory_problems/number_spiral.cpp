#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while (t--) {
    long long int row,col,ans=1;
    cin>>row>>col;
    if(row>col){
      if(row%2==0){
        ans=(row*row)-(col-1);
      }
      else{
        ans=(row-1)*(row-1)+col;
      }
    }
    else{
      if(col%2!=0){
        ans=(col*col)-(row-1);
      }
      else{
        ans=(col-1)*(col-1)+row;
      }

    }
    cout<<ans<<endl;
  }
}
