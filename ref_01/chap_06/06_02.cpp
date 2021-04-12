// a[i]<b[j]<c[k]を満たす組が何組あるか
// O(NlogN)
// b[j]を基準にするのがポイント

#include <iostream>
#include <vector>
#include <algorithm>
#define ALL(x) (x).begin(),(x).end()
using namespace std;

int	main(void)
{
	int N;
	cin >> N;
	vector<int> a(N), b(N), c(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cin >> b[i];
	for (int i = 0; i < N; ++i)
		cin >> c[i];
	sort(ALL(a));
	sort(ALL(b));
	sort(ALL(c));
	int res = 0;
	for (int j = 0; j < N; ++j){
		int i = lower_bound(ALL(a), b[j]) - a.begin();
		int k = c.end() - upper_bound(ALL(c), b[j]);
		res += i * k;
	}
	cout << res << endl;
}
