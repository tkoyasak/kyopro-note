/* ３つのものを考えるときは，真ん中を固定して考える． */

#include <bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(), (a).end()

int	main(void)
{
	int N;
	vector<int> a(N), b(N), c(N);
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < N; ++i) cin >> b[i];
	for (int i = 0; i < N; ++i) cin >> c[i];

	sort(ALL(a));
	sort(ALL(b));
	sort(ALL(c));

	long long res = 0;
	for (int i = 0; i < N; ++i) {
		long long Ai = lower_bound(ALL(a), b[i]) - a.begin();
		long long Ci = N - (upper_bound(ALL(c), b[i]) - c.begin());
		res += Ai * Ci;
	}
	cout << res << endl;
}
