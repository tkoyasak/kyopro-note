// dp[i+1][j]:a[0]..a[i]から選んで総和をjにするとき，用いる整数a[i]の個数の最小値
// *a[i]はm[i]回以下しか選べない

#include <iostream>
#include <vector>
#define MAX INT32_MAX
using namespace std;

template<class T>	inline bool	rplmin(T& a, T b)
{
	if (a > b) {a = b; return true;}
	else return false;
}

int	main(void)
{
	int N, W;
	cin >> N >> W;
	vector<int> a(N), m(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i] >> m[i];
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, MAX));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < W; ++j)
		{
			if (dp[i][j] < MAX)
				rplmin(dp[i + 1][j], 0);
			if (j + a[i] <= W && dp[i + 1][j] < m[i])
				rplmin(dp[i + 1][j + a[i]], dp[i + 1][j] + 1);
		}
	if (dp[N][W]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
