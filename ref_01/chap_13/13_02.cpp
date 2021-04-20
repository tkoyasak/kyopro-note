// code13.4をBFSで実装

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool>	seen;
queue<int>	que;

void	bfs(const Graph &G, int s){
	seen[s] = true;
	que.push(s);

	while (!que.empty()){
		int v = que.front();
		que.pop();

		for (int x: G[v]){
			if (seen[x]) continue;
			seen[x] = true;
			que.push(x);
		}
	}
}

int	main(void){
	int N, M, s, t;
	cin >> N >> M >> s >> t;

	Graph G(N);
	// 有向グラフ
	for (int i = 0; i < M; ++i){
		int n, m;
		cin >> n >> m;
		G[n].push_back(m);
	}

	seen.assign(N, false);
	bfs(G, s);

	if (seen[t]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
