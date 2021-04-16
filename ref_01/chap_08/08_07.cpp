// 整数a(N),b(M)から１つずつ選んでできる整数の組の和がKに一致するかを求める
// 平均的に O(N + M)
// ハッシュテーブルを用いる

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class	HashTable{
	int buck;
	unordered_multiset<int> *table;
public:
	HashTable(int m):buck(m){
		table = new unordered_multiset<int>[buck];
	}
	void ins(int x);
	int find(int x);
};

void	HashTable::ins(int key){
	int index = abs(key % buck);
	table[index].insert(key);
}

int	HashTable::find(int key){
	int index = abs(key % buck);
	return table[index].count(key);
}

int	main(void)
{
	int K, N, M;
	cin >> K >> N >> M;
	vector<int> a(N), b(M);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < M; ++i)
		cin >> b[i];
	int m = max(N, M);
	HashTable hash(m);
	for (int i = 0; i < N; ++i)
		hash.ins(a[i]);
	bool ok = false;
	for (int i = 0; i < M; ++i){
		if (hash.find(K - b[i]))
			ok = true;
	}
	if (ok == true)
		cout << "found" << endl;
	else
		cout << "not found" << endl;
}
