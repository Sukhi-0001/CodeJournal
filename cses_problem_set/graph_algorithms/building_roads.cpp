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

  void dfs(vector<int> &visted,ll node){
    visted[node]=1;
    for(auto ngr : edges[node]){
      if(visted[ngr]==0)
        dfs(visted,ngr);
    }
  }

  ll get_connected_components(vector<ll> &route){
    ll count=0;
    vector<int> visted(nodes,0);
    visted[0]=1;
    for(ll i=0;i<nodes;i++){
      if(visted[i]==0){
        route.push_back(i);
        count++;
        dfs(visted,i);
      }
    }
    return count;
  }
};

int main (int argc, char *argv[]) {
  ll n,m;
  cin>>n>>m;
  undirected_graph gp(n+1);
  for(int i=0;i<m;i++){
    ll s,e;
    cin>>s>>e;
    gp.add_edge(s,e);
  }

  vector<ll> route;

  ll count=gp.get_connected_components(route)-1;
  cout<<count<<endl;
  for(ll i=0;i<route.size()-1;i++){
    cout<<route[i]<<" "<<route[i+1]<<endl;
  }

  return 0;
}


