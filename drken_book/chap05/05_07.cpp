#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T& a, T b) {if (a < b) a = b;}

int	main(void)
{
	string S, T;
	cin >> S >> T;
	int N = S.size(), M = T.size();

	vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

	for (int i = 0; i < N+1; ++i) {
		for (int j = 0; j < M+1; ++j) {
			if (i > 0 && j > 0) {
				if (S[i-1] == T[j-1]) chmax(dp[i][j], dp[i-1][j-1] + 1);
				else chmax(dp[i][j], dp[i-1][j-1]);
			}

			if (i > 0)
				chmax(dp[i][j], dp[i-1][j]);

			if (j > 0)
				chmax(dp[i][j], dp[i][j-1]);
		}
	}

	cout << dp[N][M] << endl;
}