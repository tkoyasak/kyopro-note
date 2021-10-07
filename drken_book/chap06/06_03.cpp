#include <bits/stdc++.h>
using namespace std;

#define ALL(a) a.begin(),a.end()

int	main(void)
{
	int N, M;
	cin >> N >> M;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) cin >> P[i];

	P.push_back(0);
	vector<long long> S;
	for (int i = 0; i < N+1; ++i) {
		for (int j = 0; j < N+1; ++j) {
			S.push_back(P[i] + P[j]);
		}
	}
	sort(ALL(S));

	long long res = 0;
	for (long long a : S) {
		auto it = upper_bound(ALL(S), M-a);
		if (it  == S.begin()) continue;
		--it;
		res = max(res, a + *it);
	}
	cout << res << endl;

}