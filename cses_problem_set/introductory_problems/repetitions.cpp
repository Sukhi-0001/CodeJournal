#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  char prev,curr;
  curr=s[0];
prev=' ';
  int count=0,max=0;
  for(int i=0;i<s.size();i++){
    curr=s[i];
    if(prev!=curr){
      if(max<count)
        max=count;
      count=1;
    }
    else {
      count++;
    }
    prev=curr;
  }
  if(max<count)
    max=count;
 cout<<max;   
}
