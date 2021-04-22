// 迷路(HxW)を解け
// BFS

#include <bits/stdc++.h>
using namespace std;
using Maze = vector<vector<char>>;
using Board = vector<vector<int>>;

int	H, W;

void	bfs(const Maze &M, Board &dist, int sx, int sy){
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	queue<pair<int, int>> que;
	que.push(make_pair(sx, sy));

	while (!que.empty()){
		pair<int, int> cur = que.front();
		int x = cur.first;
		int y = cur.second;
		que.pop();

		for (int dir = 0; dir < 4; ++dir){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (M[nx][ny] == '#') continue;

			if (dist[nx][ny] == -1){
				que.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int	main(void){
	// H:行, W:列
	// s*:start, g*:goal
	cin >> H >> W;

	// "."道, "#"壁
	Maze M(H, vector<char>(W));
	int sx, sy, gx, gy;
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			char m;
			cin >> m;
			if (m == 'S') {sx = i; sy = j;}
			if (m == 'G') {gx = i; gy = j;}
			M[i][j] = m;
		}
	}

	// 各セルの最短距離
	Board dist(H, vector<int>(W, -1));
	dist[sx][sy] = 0;

	bfs(M, dist, sx, sy);

	if (dist[gx][gy] != -1) cout << "goal" << endl;
	else cout << "not goal" << endl;

	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			if (M[i][j] == '#' || dist[i][j] == -1) cout << setw(3) << M[i][j];
			else cout << setw(3) << dist[i][j];
		}
		cout << endl;
	}
}
