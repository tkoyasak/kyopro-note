#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T& a, T b) {if(a<b)a=b;}
template<class T> void chmin(T& a, T b) {if(a>b)a=b;}

const long long INF = 1LL << 60;

int	main(void)
{
	int N;
	cin >> N;
	vector<long long> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	vector<long long> S(N+1, 0);
	for (int i = 0; i < N; ++i) S[i+1] = S[i] + a[i];

	vector<vector<long long>> dp(N+1, vector<long long>(N+1, INF));

	for (int i = 0; i < N; ++i) dp[i][i+1] = 0;

	for (int bet = 0; bet < N; ++bet) {
		for (int i = 0; i + bet <= N; ++i) {
			int j = i + bet;

			for (int k = i+1; k < j; ++k)
				chmin(dp[i][j], dp[i][k] + dp[k][j] + S[j]-S[i]);
		}
	}

	cout << dp[0][N] << endl;
}