const int MAXN=200;
ll g[MAXN][MAXN];
int p[MAXN][MAXN];
// ensure g[i][i] = 0 and g[i][j] = INF if theres is no edge i-j;

void floyd_warshall(){
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

void retrieve_path(int u, int v){

}
