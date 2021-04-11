#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int	main(void)
{
	int N, nb;
	string S;
	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		nb += pow(10, i) * (S[N - i - 1] - '0');
	cout << nb << endl;
}
