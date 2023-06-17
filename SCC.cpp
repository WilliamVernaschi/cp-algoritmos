// Strongly connected components
// status: not tested
//
/*
EXAMPLE USAGE:
int main(){
  int n, m; cin >> n >> m;
  g.resize(n), gT.resize(n);
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    // assumes vertices are 1-indexed;
    u--, v--;

    g[u].PB(v);
    gT[v].PB(u);
  }
  scc();
  cout << comp_cnt << '\n';
}

*/

vector<int> top_ord(){
  int n = g.size();
  vector<bool> vis(n, false);
  vector<int> top_order;

  function<void(int)> dfs_visit = [&](int u){
    vis[u] = true;
    for(int v : g[u]) if(!vis[v]) dfs_visit(v);
    top_order.PB(u);

  };

  for(int u = 0; u < n; u++){
    if(!vis[u]) dfs_visit(u);
  }

  reverse(top_order.begin(), top_order.end());
  return top_order;
}

void dfs2(vector<int> &top_order){

  int comp_cnt=0;

  function<void(int)> dfs_visit = [&](int u){
    comps[u] = comp_cnt;
    for(int v : gT[u]) if(!comps[v]) dfs_visit(v);
  };

  for(int u : top_order){
    if(!comps[u]) comp_cnt++, dfs_visit(u);
  }
}

auto scc(){
  vector<int> topological_order = top_ord();
  dfs2(topological_order);

  // uncomment lines below if the condensed
  // scc graph is needed.

  vector<vector<int>> scc_graph(comp_cnt);
  vector<bool> used(comp_cnt);

  /*
  int n = g.size();
  for(int u = 0; u < n; u++){
    for(int v : g[u]){
      if(comps[u] != comps[v] && !used[v]){
        scc_graph[u].PB(v);
        used[v] = true;
      }
    }
    for(int v : g[u]){
      used[v] = false;
    }
  }
  return scc_graph;
  */

  return;

}
