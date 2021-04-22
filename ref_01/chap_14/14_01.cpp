// 有向閉路をもたない有向グラフ G = (V,E) について，最長経路の長さを求めよ
// O(|V|+|E|)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> dist;
vector<bool> seen;
int dist_max;
template<class T> void rplmax(T& a, T b){if (a < b) a = b;}

void	bfs(int s){
	queue<int> que;
	seen[s] = true;
	dist[s] = 0;
	que.push(s);

	while (!que.empty()){
		int v = que.front();
		que.pop();

		for (int x: G[v]){
			seen[x] = true;
			rplmax(dist[x], dist[v]+1);
			rplmax(dist_max, dist[x]);
			que.push(x);
		}
	}
}

int	main(void){
	int V, E;
	cin >> V >> E;

	G.resize(V);
	for (int i = 0; i < E; ++i){
		int a, b;
		cin >> a >> b;
		G[--a].push_back(--b);
	}

	seen.assign(V, false);
	dist.assign(V, -1);

	for (int i = 0; i < V; ++i)
		if (!seen[i]) bfs(i);

	cout << "max = " << dist_max << endl;
}
