// 迷路(HxW)を解け
// DFS

#include <bits/stdc++.h>
using namespace std;
using Maze = vector<vector<int>>;

vector<vector<int>>	dist;
int	H, W, s_h, s_w, g_h, g_w;

void	dfs(const Maze &M, int h, int w, int d){
	if (dist[g_h][g_w]) return;
	if (dist[h][w]) return;
	dist[h][w] = d;
	if (w+1 < W && M[h][w+1]) dfs(M, h, w+1, d+1);
	if (w-1 >= 0 && M[h][w-1]) dfs(M, h, w-1, d+1);
	if (h+1 < H && M[h+1][w]) dfs(M, h+1, w, d+1);
	if (h-1 >= 0 && M[h-1][w]) dfs(M, h-1, w, d+1);
}

int	main(void){
	// H:行, W:列
	// s_*:start, g_*:goal
	cin >> H >> W >> s_h >> s_w >> g_h >> g_w;

	// true = 1, false = 0
	Maze M(H, vector<int>(W));
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			int m;
			cin >> m;
			M[i][j] = m;
		}
	}

	dist.assign(H, vector<int>(W, 0));
	dfs(M, s_h, s_w, 0);

	if (dist[g_h][g_w]) cout << "goal" << endl;
	else cout << "not goal" << endl;
}
