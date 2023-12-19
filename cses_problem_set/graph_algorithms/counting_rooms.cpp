#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(vector<vector<int>> &visted,ll r,ll c,vector<vector<char>> &a){
  if(r<0 || r>=a.size())
    return;
  if(c<0 || c>=a[r].size())
    return;
  if(a[r][c]=='#' || visted[r][c]==1)
    return;
  visted[r][c]=1;
  dfs(visted,r+1,c,a);
  dfs(visted,r,c+1,a);
  dfs(visted,r-1,c,a);
  dfs(visted,r,c-1,a);
}

int main(){
  ll n,m;
  cin>>n>>m;
  vector<vector<char>> a(n,vector<char> (m));
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  vector<vector<int>> visted(n,vector<int> (m,0));
  ll count=0;
  for(ll i=0;i<n;i++){
    for (ll j = 0; j < m; j++) {
      if(visted[i][j]==0 && a[i][j]=='.'){
        count++;
        dfs(visted,i,j,a);
      }
      
    }
  }
  cout<<count;

}
