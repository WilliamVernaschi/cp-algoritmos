vector<vector<pii>> g;

void bellman_ford(int s){
  int n = (int)g.size();

  vector<int> d(n, INFLL);
  vector<int> p(n);
  d[s] = 0;
  bool relax=true;

  for(int u = 0; u < n-1; u++){
    relaxed = false;

    for(auto [v, w] : g[u]){
      if(d[u]+w < d[v]){
        d[v] = d[u] + w;
        p[v] = u;
        relaxed = true;
      }
    }

    if(!relaxed) break;
  }
}
