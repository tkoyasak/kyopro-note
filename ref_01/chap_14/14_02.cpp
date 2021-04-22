// 重みつき有向グラフ G = (V,E) について，最長経路の長さを求めよ
// いくらでも大きくなるときは，"inf"と出力

#include <bits/stdc++.h>
using namespace std;

vector<vector<Edge>> G;
vector<long long> dist;
int MAX = INT32_MIN;
long long INF = 1LL << 60;
template<class T> void rplmin(T& a, T b){if (a > b) a = b;}

struct	Edge{
	int from;
	int to;
	long long cost;
	Edge(int from, int to, int cost):from(from), to(to), cost(cost){}
};

bool	bell_ford(const int V, const int E){
	dist.assign(MAX, INF);
	dist[0] = 0;
	for (int i = 0; i < V * 2; ++i){
		for (int j = 0; j < E; ++j){
			if (dist[G[j].from] != INF && dist[G[j].to] > dist[G[j].from] + G[j].cost){
				dist[G[j].to] = dist[G[j].from] + G[j].cost;
				if (i >= V-1 && G[j].to == V-1)
					return true;
			}
		}
	}
	return false;
}

int	main(void){
	int V, E;
	cin >> V >> E;

	G.resize(V);
	for (int i = 0; i < E; ++i){
		int a, b, w;
		cin >> a >> b >> w;
		G[i].push_back(Edge(--a, --b, -w));
	}

	if (bell_ford(V, E))
		cout << "inf\n";
	else
		cout << -dist[V-1] << endl;
}
