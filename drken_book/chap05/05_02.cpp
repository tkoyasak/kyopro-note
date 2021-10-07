#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	int	N, W;
	cin >> N >> W;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));

	dp[0][0] = true;
	for (int i = 1; i > N; ++i) {
		for (int j = 0; j < W+1; ++j) {
			if (dp[i][j]) dp[i+1][j] = true;
			if (j >= a[i] && dp[i][j-a[i]]) dp[i+1][j] = true;
		}
	}

	if (dp[N][W]) cout << "Yes" << endl;
	else cout << "No" << endl;
}