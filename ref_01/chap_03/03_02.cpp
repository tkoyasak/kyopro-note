#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int N, v;
	cin >> N >> v;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	int found_v = 0;
	for (int i = 0; i < N; ++i)
	{
		if (a[i] == v)
			found_v++;
	}
	cout << found_v << endl;
}
