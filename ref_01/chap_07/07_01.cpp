// a(N)とb(N)から選んでペア(a[i]<b[j])をつくるとき，最大何ペアできるか
// O(NlogN)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	int N;
	cin >> N;
	vector<int> a(N), b(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i] >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int res = 0, j = 0;
	for (int i = 0; i < N; ++i){
		j = lower_bound(b.begin() + j, b.end(), a[i] + 1) - b.begin();
		if (j == N)	break;
		++res;
		++j;
	}
	cout << res << endl;
}
