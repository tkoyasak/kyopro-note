// トポロジカルソートの実装
// BFS

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool>	seen;
queue<int>	que;
vector<int>	order;

void	bfs(){

}

int	main(void){
	int N, M;
	cin >> N >> M;
	Graph G(N);
	for (int i = 0; i < M; ++i){
		int m, n;
		cin >> m >> n;
		G[m].push_back(n);
	}

	seen.assign(N, false);
	order.clear();
	for (int v = 0; v < N; ++v){
		if (seen[v]) continue;
		bfs();
	}

	for (auto v: order)
		cout << v << " -> ";
	cout << endl;
}
