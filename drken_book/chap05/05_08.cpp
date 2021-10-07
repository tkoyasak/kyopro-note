#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 29;

template<class T> void chmax(T& a, T b) {if (a < b) a = b;}

int	main(void)
{
	int N, M;
	cin >> N >> M;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	vector<vector<int>> f(N+1, vector<int>(N+1));

	for (int i = 1; i < N+1; ++i) {
		for (int j = 0; j < i; ++j) {
			int sum = 0;
			for (int k = j; k < i; ++k) sum += a[k];
			f[j][i] = sum / (i - j);
		}
	}

	vector<vector<int>> dp(N+1, vector<int>(M+1, -INF));

	for (int i = 0; i < N+1; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 1; k < M+1; ++k)
				chmax(dp[i][k], dp[j][k-1] + f[k][i]);
		}
	}

	int res = -INF;
	for (int i = 0; i < M+1; ++i) chmax(res, dp[N][i]);
	cout << res << endl;
}