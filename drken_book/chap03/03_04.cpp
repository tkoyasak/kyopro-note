#include <bits/stdc++.h>
using namespace std;
const int INF = 20000000;

int	main(void)
{
	int	N;
	cin >> N;
	vector<int>	a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	int	max_value = -INF;
	int	min_value = INF;
	for (int i = 0; i < N; ++i) {
		if (a[i] < min_value)
			min_value = a[i];
		if (max_value < a[i])
			max_value = a[i];
	}

	cout << max_value - min_value << endl;
}