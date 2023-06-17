// Disjoint Set Union Find

// EXAMPLE USAGE:
/*
*counting connect components*

int main(){
  
  int n, m; cin >> n >> m;

  DSU dsu(n);

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    // assumes u and v are 1-indexed
    u--, v--;

    dsu.onion(u, v);
  }

  vector<bool> found(n);
  int comp_count=0;
  for(int i = 0; i < n; i++){
    if(!found[i]) found[i]=++comp_count;
  }

  cout << comp_count << '\n'
}
*/
struct DSU{

  int n;
  vector<int> parent, sz;

  DSU(int n) : parent(n), sz(n) {
    for(int i = 0; i < n; i++) parent[i] = i;
    this->n = n;
  };

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

