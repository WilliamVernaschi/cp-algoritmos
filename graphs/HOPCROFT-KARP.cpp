#include <vector>
#include <iostream>
#include <queue>

using namespace std;

std::vector<std::vector<int>> adj;
std::vector<int> pairs, dist, ptr;

bool bfs(int n) {
	queue<int> q;

	for(int i = 0; i < n; i++) {
		if(pairs[i] < 0){
      dist[i] = 0; q.push(i);
    }
		else dist[i] = -1;
	}

  bool exist = false;
	while(!q.empty()) {
		int u = q.front(); q.pop();

		for(int v : adj[u]) {
			if(pairs[v] < 0){
        exist = true;
        continue;
      }
			if(dist[pairs[v]] < 0) {
				dist[pairs[v]] = dist[u] + 1;
				q.push(pairs[v]);
	    }
    }
  }
	return exist;
}

bool dfs(int u) { 
	for(; ptr[u] < (int)adj[u].size(); ptr[u]++){
    int v = adj[u][ptr[u]];

		if(pairs[v] < 0 || (dist[pairs[v]] > dist[u] && dfs(pairs[v]))){
			pairs[v] = u; pairs[u] = v;
			return true;
    }
  }

	return false;
}

int hopcroft_karp(int n) {
	int ans = 0;
	pairs.assign((int)adj.size(), -1);
	dist.resize(n);
	for(int i = 0; i < n; i++)
    for(int w : adj[i])
		  if(pairs[w] < 0)
        {pairs[i] = w; pairs[w] = i; ans++; break;}

	while(bfs(n)){
    ptr.assign(n, 0);
    for(int i = 0; i < n; i++)
      if(pairs[i] < 0) ans += dfs(i);
  }
	return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);

  int l, r, m;
  std::cin >> l >> r >> m;

  std::vector<std::vector<int>> g(l+r);

  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(l + y);
  }

  adj = g;
  hopcroft_karp(l);

  std::vector<pair<int, int>> ans;
  for(int i = 0; i < l; i++)
    if(pairs[i] != -1)
      ans.emplace_back(i, pairs[i] - l);

  std::cout << (int)ans.size() << '\n';
  for(auto [x, y] : ans) {
    std::cout << x << ' ' << y << '\n';
  }
}
