// dp[i+1][j]:a[0]..a[i]から選んで総和をjにするとき，用いる整数の個数の最小値

#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int N, W, k;
	cin >> N >> W >> k;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < W; ++j)
		{
			if (dp[i][j] != -1)
				dp[i + 1][j] = dp[i][j];
			if (dp[i][j] != -1 && j + a[i] <= W)
				dp[i + 1][j + a[i]] = dp[i][j] + 1;
		}
	if (dp[N][W] != -1 && dp[N][W] <= k) cout << "Yes" << endl;
	else cout << "No" << endl;
}
