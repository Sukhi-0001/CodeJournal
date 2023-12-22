#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class undirected_graph{
  ll nodes;
  vector<vector<ll>> edges;
  public:

  undirected_graph(ll size){
    nodes=size;
    edges.resize(nodes);
  }

  void add_edge(ll s,ll e){
    edges[s].push_back(e);
    edges[e].push_back(s);
  }


  int bfs(ll node,ll end,vector<ll> &parent){
    vector<int> visted(nodes+1,0);
    queue<ll> q;
    q.push(node);
    parent[node]=node;
    visted[node]=1;
    while (!q.empty()) {
      ll ngr=q.front();
      
      q.pop();
      if(ngr==end)
        return 1;
      for(auto ele : edges[ngr]){
        if(visted[ele]==0){
          visted[ele]=1;
          parent[ele]=ngr;
          q.push(ele);
        }
      }
    }
    return 0;
  }

};

int main (int argc, char *argv[]) {
  ll n,m;
  cin>>n>>m;
  undirected_graph gp(n+1);
  ll s,e;
  for(ll i=0;i<m;i++){
    cin>>s>>e;
    gp.add_edge(s,e);
  }
  vector<ll> parent(n+1);
  int ans=gp.bfs(1,n,parent);
  if(ans==0){
    cout<<"IMPOSSIBLE";
    return 0;
  }
  vector<ll> route;
  ll node=n;
  while(node!=parent[node]){
    route.push_back(node);
    node=parent[node];
  }
  route.push_back(1);
  cout<<route.size()<<endl;

  for(ll i=route.size()-1;i>=0;i--){
    cout<<route[i]<<" ";
  }
  return 0;
}
