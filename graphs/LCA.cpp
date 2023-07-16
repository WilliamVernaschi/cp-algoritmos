int n;
vector<vector<int>> g(n);
vector<int> pai(n), prof(n);

function<void(int ,int)> dfs = [&](int u, int p){
  pai[u] = p;
  for(int v : adj[u]){
    if(v == p) continue;
    prof[v] = prof[u] + 1;
    dfs(v, u);
  }
};

dfs(0, -1);

int lg = __lg(n);
vector<vector<int>> pai_lg(lg, vector<int>(n, -1));
for(int i = 0; i < n; i++){
  pai_lg[0][i] = pai[i];
}

for(int i = 1; i < lg; i++){
  for(int j = 0; j < n; j++){
    if(pai_lg[i-1][j] == -1) continue;

    pai_lg[i][j] = pai_lg[i-1][pai_lg[i-1][j]];
  }
}

auto jump = [&](int u, int k){
  for(int i = 0; i < lg; i++){
    if((1<<i) & k){
      u = pai_lg[i][u];
    }
  }
  return u;
};

auto lca = [&](int u, int v){
  if(prof[u] < prof[v]) swap(u, v);
  u = jump(u, prof[u] - prof[v]);
  if(u == v) return u;
  for(int i = lg-1; i >= 0; i--){
    if(pai_lg[i][u] != pai_lg[i][v]){
      u = pai_lg[i][u];
      v = pai_lg[i][v];
    }
  }
  return pai[u];
};
 
