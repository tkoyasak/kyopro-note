#include <iostream>
#include <vector>
#define MAX INT32_MAX
#define MIN INT32_MIN
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	int min = MAX, max = MIN;
	for (int i = 0; i < N; ++i)
	{
		if (a[i] < min)
			min = a[i];
	}
	for (int i = 0; i < N; ++i)
	{
		if (max < a[i])
			max = a[i];
	}
	cout << max - min << endl;
}
