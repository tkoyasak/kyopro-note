// 空のヒープに{5,6,1,2,7,3,4}を挿入．配列で表せ．

#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
using namespace std;

struct	Heap{
	vector<int> heap;
	Heap(){}

	void	push(int x){
		heap.push_back(x);
		int c = (int)heap.size() - 1;
		while (c > 0){
			int p = (c - 1) / 2;
			if (heap[p] >= x) break;
			heap[c] = heap[p];
			c = p;
		}
		heap[c] = x;
	}

	int	print(int i){
		// if (heap[i]) return heap[i];
		// else return -1;
		return heap[i];
	}
};

int	main(void){
	Heap h;

	h.push(5);	h.push(6);	h.push(1);	h.push(2);	h.push(7);	h.push(3);	h.push(4);

	for (int i = 0; i < 7; ++i)
		cout << h.print(i) << endl;
}
