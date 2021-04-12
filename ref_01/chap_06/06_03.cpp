// a(N)から重複を許して4個選んだ総和のうち，Mを超えない最大値
// O((N^2)logN)

#include <iostream>
#include <vector>
#include <algorithm>
#define ALL(x) (x).begin(),(x).end()
using namespace std;

template<class T>	inline bool	rplmax(T& a, T b)
{
	if (a < b) {a = b; return true;}
	else return false;
}

int	main(void)
{
	int N, M;
	cin >> N >> M;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(ALL(a));
	int res = 0;


	cout << res << endl;
}
