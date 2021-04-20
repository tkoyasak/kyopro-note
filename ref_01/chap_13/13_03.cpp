// code13.5をBFSで実装

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int>	color;
queue<int>	que;

bool	bfs(const Graph &G, int s){
	color[s] = 0;
	que.push(s);

	while (!que.empty()){
		int v = que.front();
		int cur = color[v];
		que.pop();

		for (int x: G[v]){
			if (color[x] != -1) {
				if (color[x] == cur) return false;
				color[x] = 1 - cur;
				continue;
			}
		}
	}
	return true;
}

int	main(void){
	int N, M, s, t;
	cin >> N >> M >> s >> t;

	Graph G(N);
	// 無向グラフ
	for (int i = 0; i < M; ++i){
		int n, m;
		cin >> n >> m;
		G[n].push_back(m);
		G[m].push_back(n);
	}

	color.assign(N, -1);
	bool is_bipartite = true;
	for (int v = 0; v < N; ++v){
		if (color[v] != -1) continue;
		if (!bfs(G, v)) is_bipartite = false;
	}

	if (is_bipartite) cout << "Yes" << endl;
	else cout << "No" << endl;
}
