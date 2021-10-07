#include <bits/stdc++.h>
using namespace std;
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int	main(void)
{
	int	N;
	cin >> N;
	vector<vector<int>> abc(N, vector<int>(3));
	for (int i = 0; i < N; ++i)
		cin >> abc[i][0] >> abc[i][1] >> abc[i][2];

	vector<vector<int>> dp(N+1, vector<int>(3, 0));

	for (int i = 1; i < N + 1; ++i) {
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + abc[i-1][0];
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + abc[i-1][1];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + abc[i-1][2];
	}

	int	res = 0;
	for (int i = 0; i < 3; ++i) chmax(res, dp[N][i]);
	cout << res << endl;
}