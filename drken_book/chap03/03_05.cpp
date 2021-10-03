#include <bits/stdc++.h>
using namespace std;
const int INF = 20000000;


int	how_many_times(int n)
{
	int	count = 0;
	while (!(n % 2)) {
		n /= 2;
		count++;
	}
	return count;
}

int	main(void)
{
	int	N;
	cin >> N;
	vector<int>	a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	int	min_count = INF;
	for (auto i: a) {
		min_count = min(min_count, how_many_times(i));
	}

	cout << min_count << endl;
}
