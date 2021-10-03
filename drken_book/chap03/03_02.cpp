#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	int	N, v;
	cin >> N >> v;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	int	count = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] == v)
			count++;
	}

	cout << count << endl;
}
