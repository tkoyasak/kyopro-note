// 無向グラフの連結成分の個数を数える

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int res;
vector<bool> seen;

void	dfs(const Graph &G, int v){
	seen[v] = true;
	for (auto next_v: G[v]){
		if (seen[next_v]) continue;
		dfs(G, next_v);
	}
}

int	main(void){
	// N:頂点数,M:辺数
	int N, M;
	cin >> N >> M;

	Graph G(N);
	// 無向グラフ
	for (int i = 0; i < M; ++i){
		int m, n;
		cin >> m >> n;
		G[m].push_back(n);
		G[n].push_back(m);
	}

	seen.assign(N, false);
	for (int v= 0; v < N; ++v){
		if (seen[v]) continue;
		++res;	dfs(G, v);
	}

	std::cout << res << endl;
}
