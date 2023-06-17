// DIJKSTRAS'S SHORTEST PATH ALGORITHM
// from cp-algorithms.com
/*
EXAMPLE USAGE:
int main(){
  int n, m; cin >> n >> m;
  g.resize(n);

  for(int i = 0; i < m; i++){
    // assumes vertices are 1-indexed
    int u, v, w; cin >> u >> v >> w; u--, v--;
    g[u].emplace_back(v, u);
  }

  // prints the distance from vertex 0 to every
  // other vertex
  for(int u : dijkstra(0)){
    cout << u << ' ';
  }
  cout << '\n';
}
*/

vector<vector<pair<int, ll>>> g;

vector<ll> dijkstra(int s){
  int n = (int)g.size();

  vector<ll> d(n, INFLL);
  vector<int> p(n, -1);

  d[s] = 0;
  set<pair<ll, int>> pq;
  pq.insert({0, s});

  while(!pq.empty()) {
    int v = pq.begin()->second;
    pq.erase(pq.begin());

    for(auto [to, w] : g[v]){

      if(d[v] + w < d[to]){
        pq.erase({d[to], to});
        d[to] = d[v] + w;
        p[to] = v;
        pq.insert({d[to], to});
      }
    }
  }
  return d;
}
