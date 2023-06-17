// Diameter of a Tree
// status: tested

int get_diameter(vector<vector<int>> &g){
  int n = g.size();
  vector<int> dist(n);

  auto bfs = [&](int init){
    dist.assign(n, INF);
    dist[init] = 0;
    queue<int> q;
    q.push(init);

    int far = 0;

    while(!q.empty()){
      int u = q.front();
      if(dist[u] > dist[b]) far = i;
      q.pop();
      for(int v : g[u]){
        if(dist[v] != INF) continue;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }

    return far;
  };

  return dist[bfs(bfs(0))];
}
