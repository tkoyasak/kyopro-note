#include <bits/stdc++.h>
using namespace std;

vector<long long> memo;

int	tribo(int N)
{
	if (N == 0 || N == 1)
		return 0;
	else if (N == 2)
		return 1;

	if (memo[N] != -1)
		return memo[N];

	return memo[N] = tribo(N-1) + tribo(N-2) + tribo(N-3);
}

int	main(void)
{
	int	N;

	memo.assign(N+1, -1);

	cout << tribo(N) << endl;
}