/* N 個の小屋から M 個を選ぶ。このとき、どの 2 つの小屋の間隔も x 以上離れている状態にすることは可能か？ */
/* 問題の答えは「上記の判定問題の答えが Yes であるような最大の x」になります。 */

#include <bits/stdc++.h>
using namespace std;

#define ALL(a) a.begin(),a.end()

const long long INF = 1LL << 50;

int	main(void)
{
	int N, M;
	cin >> N >> M;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	long long left = 0, right = INF;
	while (right - left > 1) {
		long long x = (right + left) / 2;

		int cnt = 1;
		int prev = 0;
		for (int i = 0; i < N; ++i) {
			if (a[i] - a[prev] >= x) {
				++cnt;
				prev = i;
			}
		}
		if (cnt >= M) left = x;
		else right = x;
	}
	cout << left << endl;
}