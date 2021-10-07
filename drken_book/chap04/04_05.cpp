#include <bits/stdc++.h>
using namespace std;

void	func(long long N, long long cur, int use, long long &count)
{
	if (cur > N)
		return ;
	if (use == 0b111)
		count++;

	func(N, cur * 10 + 7,  use | 0b001, count);
	func(N, cur * 10 + 5,  use | 0b010, count);
	func(N, cur * 10 + 3,  use | 0b100, count);
}

int	main(void)
{
	long long	K;
	cin >> K;

	long long	count = 0;
	func(K, 0, 0, count);
	cout << count << endl;
}