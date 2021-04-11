// N日間の幸福度:dp[i+1][j]
// 最後の日の行動について，j=0:海で泳ぐ, j=1:虫取りをする, j=2:宿題をする

#include <iostream>
#include <vector>
using namespace std;

template<class T>	inline bool	rplmax(T& a, T b)
{
	if (a < b) {a = b; return true;}
	else return false;
}

int	main(void)
{
	int N;
	cin >> N;
	vector<vector<int>> h(N, vector<int>(3));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> h[i][j];
	vector<vector<int>> dp(N + 1, vector<int>(3, 0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
			{
				if (j == k) continue;
				rplmax(dp[i + 1][k], dp[i][j] + h[i][k]);
			}
	int res = 0;
	for (int i = 0; i < 3; ++i)
		rplmax(res, dp[N][i]);
	cout << res << endl;
}
