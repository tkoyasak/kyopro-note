// dp[i+1][j]:a[0]..a[i]から選んで総和をjにできるか

#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int N, W;
	cin >> N >> W;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
	dp[0][0] = true;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < W; ++j)
		{
			// dp[i+1][j] |= dp[i][j]
			if (dp[i][j])
				dp[i + 1][j] = true;
			// dp[i+1][j+a[i]] |= dp[i][j]
			if (dp[i][j] && j + a[i] <= W)
				dp[i + 1][j + a[i]] = true;
		}
	int count = 0;
	for (int j = 1; j <= W; ++j)
		if (dp[N][j]) ++count;
	cout << count << endl;
}
