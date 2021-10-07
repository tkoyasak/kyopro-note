#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int	func(int i, int w, vector<int> &a)
{
	if (i == 0) {
		if (w == 0) return true;
		else return false;
	}

	if (memo[i][w] != -1) return memo[i][w];

	if (func(i-1, w, a)) return memo[i][w] = true;

	if (func(i-1, w-a[i-1], a)) return memo[i][w] = true;

	return memo[i][w] = false;
}

int	main(void)
{
	int	N, W;
	vector<int>	a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	memo.assign(N+1, vector<int>(W+1, -1));

	if (func(N, W, a)) cout << "Yes" << endl;
	else cout << "No" << endl;
}