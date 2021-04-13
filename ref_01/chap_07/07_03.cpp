// i番目の仕事は，時間w[i][0]要し，時刻w[i][1]締め切り．複数の仕事は同時に進められない．
// 時刻0から仕事を始めたとき，全ての仕事を完了できるか
// O(N logN)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	int N;
	cin >> N;
	vector<vector<int>> w(N, vector<int>(2));
	for (int i = 0; i < N; ++i)
		cin >> w[i][0] >> w[i][1];
	sort(w.begin(), w.end(), [](const vector<int> &a, const vector<int> &b){return a[1] < b[1];});
	bool ok = false;
	int start;
	for (int i = N - 1; i >= 0; --i){
		start = w[i][1] - w[i][0];
		if (i == 0 && start >= 0)	ok = true;
		if (w[i - 1][1] > start)	break;
	}
	cout << boolalpha << ok << endl;
}
