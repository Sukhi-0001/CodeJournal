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

  void bfs(ll node){
    vector<int> visted(nodes,0);
    queue<ll> q;
    q.push(node);
    while (!q.empty()) {
      ll ngr=q.front();
      q.pop();
      for(auto ele : edges[ngr]){
        if(visted[ele]==0){
          visted[ele]=1;
          q.push(ele);
        }
      }
    }
  }

  ll get_connected_components(){
    ll count=0;
    vector<int> visted(nodes,0);
    for(ll i=0;i<nodes;i++){
      if(visted[i]==0){
        count++;
        dfs(visted,i);
      }
    }
    return count;
  }

  void is_bipartite_dfs(vector<int> visted){
    
  }
  
  void is_bipartite(){

  }

  void dijkstra(){

  }
};

int main (int argc, char *argv[]) {
  
  return 0;
}
