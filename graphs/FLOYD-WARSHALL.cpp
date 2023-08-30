const int MAXN=200;
ll g[MAXN][MAXN];
const int INF = 1e9+7;
int p[MAXN][MAXN];
// ensure g[i][i] = 0 and g[i][j] = INF if theres is no edge i-j;

/*
if weight are real:
if (d[i][k] + d[k][j] < d[i][j] - EPS)
    d[i][j] = d[i][k] + d[k][j]; 

    after the end, if there's a negative weight cycle, d[i][i] < 0
  */

void floyd_warshall(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(g[i][j] == INF) p[i][j] = -1;
      else p[i][j] = j;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][k] < INF && g[k][j] < INF){
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]); 
          p[i][j] = k;
        }
      }
    }
  }
}

vector<int> retrieve_path(int u, int v){
  // If there's no path between
  // node u and v, simply return
  // an empty array
  if (p[u][v] == -1)
      return {};

  // Storing the path in a vector
  vector<int> path = { u };
  while (u != v) {
      u = p[u][v];
      path.push_back(u);
  }
  return path;
}
