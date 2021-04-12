#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	int N;
	cin >> N;
	vector<int> a(N), c(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	c.assign(a.begin(), a.end());
	sort(c.begin(), c.end());
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (a[i] == c[j]){
				cout << j << endl;
				continue;
			}
		}
	}
}
