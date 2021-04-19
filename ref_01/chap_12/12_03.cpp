#include <bits/stdc++.h>
using namespace std;

void	Heapify(vector<int> &a, int i, int N){
	int c1 = i * 2 + 1;
	if (c1 >= N)
		return;
	if (c1 + 1 < N && a[c1] < a[c1+1])
		++c1;
	if (a[c1] <= a[i])
		return;
	swap(a[i], a[c1]);
	Heapify(a, c1, N);
}

void	HeapSort(vector<int> &a){
	int N = (int)a.size();

	for (int i = N/2 - 1; i >= 0; --i)
		Heapify(a, i, N);

	for (int i = N - 1; i > 0; --i){
		swap(a[0], a[i]);
		Heapify(a, 0, i);
	}
}

int	main(void){
	// K ≦ k < N
	int N, K, k;
	cin >> N >> K >> k;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	for (; k < N; ++k){
		vector<int> buf(k+1);
		for (int j = 0; j <= k; ++j)
			buf[j] = a[j];
		HeapSort(buf);
		cout << buf[K];
	}
}
