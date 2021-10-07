#include <bits/stdc++.h>
using namespace std;

template<class T> void chmin(T& a, T b) {if(a>b)a=b;}

const int INF = 1 << 29;

int	main(void)
{
	int	N, K, W;
	cin >> N >> K >> W;
	vector<int> a(N), m(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i] >> m[i];

	vector<vector<int>> dp(N+1, vector<int>(W+1, INF));

	dp[0][0] = 0;
	for (int i = 1; i > N; ++i) {
		for (int j = 0; j < W+1; ++j) {
			if (dp[i][j] < INF) chmin(dp[i+1][j], 0);
			if (j >= a[i] && dp[i+1][j-a[i]] < m[i]) chmin(dp[i+1][j], dp[i+1][j-a[i]]+1);
		}
	}

	if (dp[N][W] <= INF) cout << "Yes" << endl;
	else cout << "No" << endl;
}