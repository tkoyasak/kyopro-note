// サイズNの連結リストにおいて,headからスタートしてi番目の要素を取得する関数get(i)
// このときmain関数の計算量
// O(0.5(N^2 - N))

#include <iostream>
using namespace std;

// 連結リストの各ノードを表す構造体
struct	Node{
	Node *next;
	string name;
	Node(string name_ = ""):
	next(NULL), name(name_){}
};

// 番兵を表すノード
Node *nil;

// 初期化
void	init()
{
	nil = new Node();
	nil->next = nil;
}

string	get(int m){
	Node* cur = nil->next;
	for (int i = 0; i < m; ++i)
		cur = cur->next;
	return (cur->name);
}

int	main(void)
{
	int N;
	cin >> N;
	init();
	for (int i = 0; i < N; ++i)
		cout << get(i) << endl;
}
