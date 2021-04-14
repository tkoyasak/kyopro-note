// 連結リストの各ノードに格納された値を順に出力する関数printListの処理に要する計算量を評価
// O(N)

#include <iostream>
using namespace std;

// 連結リストの各ノードを表す構造体
struct	Node{
	Node *prev, *next;
	string name;
	Node(string name_ = ""):
	prev(NULL), next(NULL), name(name_){}
};

// 番兵を表すノード
Node *nil;

// 初期化
void	init()
{
	nil = new Node();
	nil->prev = nil;
	nil->next = nil;
}

void	printList(){
	Node* cur = nil->next;
	for (; cur != nil; cur = cur->next)
		cout << cur->name << "->";
	cout << endl;
}

