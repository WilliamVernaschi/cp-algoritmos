// Kruskal's Minimum Spanning Tree
// status: tested

/*
EXAMPLE USAGE: 

int main(){
  cin >> n >> m;

  // fill in the `edges` array:
  for(int i = 0; i < m; i++){
    
    int u, v, w; cin >> u >> v >> w;

    // assumes u and v are 1-indexed
    u--, v--;

    // if edge {u, v} was added, then edge {v, u} need not be added.
    edges[i] = {w, {u, v}};
  }

  ll mst_weight = MST();
}
*/ 

const int MAXN = 1e6+5;
int parent[MAXN], sz[MAXN];

int n, m; // num of vertices, num of edges `cin >> n >> m` in main

struct DSU{
  void make(int n){
    for(int i = 0; i < n; i++) parent[i] = i, sz[i] = 1;
  }

  int find(int v){
    return parent[v] == v ? v : (parent[v] = find(parent[v]));
  }

  void onion(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;

    if(sz[u] > sz[v]) swap(u, v);

    parent[u] = v;
    sz[v] += sz[u];
  }
};


pair<ll, pii> edges[MAXN];

// uncomment lines below if an actual MST is needed.
ll MST(){
  // m is the number of edges
  sort(edges, edges+m);

  ll total=0;

  //vector<vector<pair<int, ll>>> mst(n);

  for(int i = 0; i < m; i++){
    auto w = edges[i].F;
    auto e = edges[i].S;
    if(dsu.find(e.F) != dsu.find(e.S)){
      dsu.onion(e.F, e.S);
      total += w;
      // mst[e.F].emplace_back(e.S, w);
      // mst[e.S].emplace_back(e.F, w);
    }
  }

  return total;
  // return mst;
}
