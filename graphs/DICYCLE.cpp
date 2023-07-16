// Checks if there is a cycle in a directed
// graph and finds it in O(V+E)
vector<vector<int>> g;


// uncomment lines to return the cycle itself
auto hasCycle(){
  int n = g.size();
  vector<int> color(n, false);
  //stack<int> grey;

  bool found = false;
  int start_cycle=-1, end_cycle=-1;
  function<void(int)> dfs = [&](int v){
    if(found) return;

    color[v] = 1;
    // grey.push(v);

    for(int u : g[v]){
      if(color[u] == 1){
        start_cycle = u, end_cycle = v;
        grey.push(u), found = true;
        return;
      }

      else if(color[u] == 0) 
        dfs(u);
    }
    if(found) return;

    // grey.pop();
    color[v] = 2;
  };


  for(int i = 0; i < n; i++)
    if(color[i] == 0 && !found)
      dfs(i);


  /*
  int first = grey.top();
  vector<int> cyc;
  cyc.PB(first+1);
  grey.pop();

  while(!grey.empty()){
    cyc.PB(grey.top()+1);
    if(grey.top() == first) break;
    grey.pop();
  }

  reverse(cyc.begin(), cyc.end());

  return cyc;
  */
  
  return found;
}
