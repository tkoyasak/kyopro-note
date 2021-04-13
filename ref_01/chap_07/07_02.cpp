// 2次元平面上にa(N,2),b(N,2)があり，ペア(x座標・y座標ともにaの方が小さい)をつくるとき，最大何ペアできるか
// O(N logN)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	int N;
	cin >> N;
	vector<vector<int>> a(N, vector<int>(2)), b(N, vector<int>(2));
	for (int i = 0; i < N; ++i){
		cin >> a[i][0] >> a[i][1];
		cin >> b[i][0] >> b[i][1];
	}
	// x座標を基準にソート
	sort(a.begin(), a.end(), [](const vector<int> &i, const vector<int> &j){return i[0] < j[0];});
	sort(b.begin(), b.end(), [](const vector<int> &i, const vector<int> &j){return i[0] < j[0];});
	int res = 0, j = 0;
	for (int i = 0; i < N; ++i){
		j = lower_bound(b.begin() + j, b.end(), a[i][0] + 1) - b.begin();
		if (j == N)	break;
		if (a[i][1] < b[j][1])
			++res;
		++j;
	}
}
