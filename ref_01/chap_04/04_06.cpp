#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memo;

bool func(int i, int W, const vector<int> &a)
{
	if (i == 0)
	{
		if (W == 0) return true;
		else return false;
	}
	if (memo[i][W] != -1)
		return memo[i][W];
	if (func(i - 1, W, a))
		return memo[i][W] = true;
	if (func(i - 1, W - a[i - 1], a))
		return memo[i][W] = true;
	return memo[i][W] = false;
}

int	main(void)
{
	int N, W;
	cin >> N >> W;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	memo.assign(N + 1, vector<int>(W + 1, -1));
	if (func(N, W, a)) cout << "Yes" << endl;
	else cout << "No" << endl;
}
