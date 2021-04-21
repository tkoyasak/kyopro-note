// トポロジカルソートの実装
// BFS
// https://qiita.com/drken/items/996d80bcae64649a6580#3-4-%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

// 各頂点の出次数
vector<int>	deg;
vector<int>	order;
queue<int>	que;


void	bfs(const Graph &G){
	while (!que.empty()){
		int v = que.front();
		que.pop();
		order.push_back(v);

		for (auto x: G[v]){
			--deg[x];
			if (deg[x] == 0) que.push(x);
		}
	}
}

int	main(void){
	int N, M;
	cin >> N >> M;
	Graph G(N);
	deg.assign(N, 0);
	for (int i = 0; i < M; ++i){
		int a, b;
		cin >> a >> b;
		G[b].push_back(a); // 逆向きに辺を張る
		deg[a]++;
	}

	for (int i = 0; i < N; ++i)
		if (deg[i] == 0) que.push(i);

	bfs(G);
	reverse(order.begin(), order.end());

	for (auto v: order)
		cout << v << " -> ";
	cout << endl;
}
