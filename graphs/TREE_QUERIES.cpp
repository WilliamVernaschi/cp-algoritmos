
auto make_euler_tour = [&](){
  int time = 0;
  //vector<int> euler(2*(int)g.size());
  function<void(int, int)> dfs = [&](int u, int p){
    first[u] = time;
    euler[time] = u;
    time++;

    for(int v : g[u]){
      if(v == p) continue;
      dfs(v, u);
    }

    last[u] = time;
    euler[time] = u;
    time++;
  };
}


/* functions for path query */
auto path_query = [&](int u, int v){
  int root_to_u = bit.get_sum(0, first[u]),
      root_to_v = bit.get_sum(0, first[v]),
      root_to_lca = bit.get_sum(0, first[lca(u, v)]);

  return root_to_u + root_to_v - root_to_lca;
};
auto vertex_update_path(int u, int val){
  bit.add(first[u], val);
  bit.add(last[u], -val);
}
/* functions for path query */


/* functions for subtree query */
auto subtree_query = [&](int u){
  return bit.get_sum(first[v], last[v]);
}
auto vertex_update_subtree = [&](int u, int val){
  bit.add(first[u], val);
}
/* functions for subtree query */

