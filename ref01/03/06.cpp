#include <iostream>
using namespace std;

// condition (x + y + z == N, 0 ≦ x, y, z ≦ K)
int main(void)
{
	int K, N;
	cin >> K >> N;
	int count = 0;
	for (int x = 0; x <= min(K, N); x++)
	{
		for (int y = 0; y <= min(K, N); y++)
		{
			int z = N - x - y;
			if (0 <= z && z <= K)
					count++;
		}
	}
	cout << count << endl;
}
