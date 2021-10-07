/* 「K 番目に小さい値を求めなさい」という問題に対しては二分探索法が有効になることがある */

#include <bits/stdc++.h>
using namespace std;

#define ALL(a) a.begin(),a.end()

int	main(void)
{
	long long N, K;
	cin >> N;
	vector<long long> a(N), b(N);
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < N; ++i) cin >> b[i];

	sort(ALL(b));

	auto check = [&](long long x) -> bool {
		long long cnt = 0;
		for (int i = 0; i < N; ++i) {
			cnt += upper_bound(ALL(b), x/a[i]) - b.begin();
		}
		return cnt >= K;
	};

	long long left = 0, right = 1LL << 60;
	while (right - left > 1) {
		long long mid = (left + right) / 2;
		if (check(mid)) right = mid;
		else left = mid;
	}
	cout << right << endl;
}