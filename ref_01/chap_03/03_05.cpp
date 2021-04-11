#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	bool flag = true;
	int cnt = 0, cnt_n;
	while (flag)
	{
		cnt_n = 0;
		for (int i = 0; i < N; ++i)
		{
			if (a[i] % 2 == 0)
			{
				a[i] /= 2;
				++cnt_n;
			}
		}
		if (cnt_n == N)
			++cnt;
		if (cnt_n != N)
			flag = false;
	}
	cout << cnt << endl;
}
