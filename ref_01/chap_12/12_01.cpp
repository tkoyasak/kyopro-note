// N個の異なる整数について，a[i]が何番目に小さいかを求める

#include <iostream>
#include <vector>
using namespace std;

void	getOrder(vector<int> &a, vector<int> &b){
	int N, vla, vlb, j;
	N = (int)a.size();
	for (int i = 1; i < N; ++i){
		vla = a[i];
		vlb = b[i];
		j = i;
		for (; j > 0; --j){
			if (a[j-1] > vla){
				a[j] = a[j-1];
				b[j] = b[j-1];
			}
			else break;
		}
		a[j] = vla;
		b[j] = vlb;
	}
}


int	main(void){
	int N;
	cin >> N;

	// b(N)は，a[i]の値が何番目に入力されたかを納める配列
	vector<int> a(N), b(N), c(N);
	for (int i = 0; i < N; ++i){
		cin >> a[i];
		b[i] = i;
	}

	getOrder(a, b);

	for (int i = 0; i < N; ++i)
		c[b[i]] = i;

	int i;
	cin >> i;
	cout << c[i] << endl;
}
