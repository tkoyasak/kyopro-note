#include <iostream>
#include <vector>
#define MAX INT32_MAX
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	int min = MAX, min_s = MAX;
	for (int i = 0; i < N; ++i)
	{
		if (a[i] < min)
			min = a[i];
	}
	for (int i = 0; i < N; ++i)
	{
		if (min < a[i] && a[i] < min_s)
			min_s = a[i];
	}
	cout << min_s << endl;
}
