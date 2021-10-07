#include <bits/stdc++.h>
using namespace std;

int	tribo(int N)
{
	if (N == 0 || N == 1)
		return 0;
	else if (N == 2)
		return 1;
	else
		return tribo(N-1) + tribo(N-2) + tribo(N-3);
}

int	main(void)
{
	int	N;
	cin >> N;

	cout << tribo(N) << endl;
}