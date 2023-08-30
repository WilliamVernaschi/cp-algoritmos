int n; cin >> n;
vector<int> color(n);
for(int i = 0; i < n; i++) cin >> color[i];
vector<vector<int>> g(n);
for(int i = 0; i < n-1; i++){
  int a, b; cin >> a >> b; a--, b--;
  g[a].PB(b);
  g[b].PB(a);
}

auto merge_sets = [&](set<int> &into, set<int> &from){
  if(into.size() < from.size()) swap(into, from);
  for(int x : from){
    into.insert(x);
  }
};
vector<int> ans(n);
function<set<int>(int,int)> dfs = [&](int v, int p){

  set<int> color_set = {color[v]};
  for(int u : g[v]) if(u != p){

    auto child = dfs(u, v);
    merge_sets(color_set, child);
  }
  ans[v] = (int)color_set.size();
  return color_set;
};

dfs(0, -1);
for(int i = 0; i < n; i++){
  cout << ans[i] << ' ';
}
cout << '\n';
