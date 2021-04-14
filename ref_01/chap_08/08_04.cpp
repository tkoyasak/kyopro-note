// 単方向リストにおいて，特定のノードvを削除する方法
// 最大でO(N)

#include <iostream>
#include <vector>
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

struct Node *get_node(string v){
	Node* cur = nil->next;
	for (; cur->next!= nil; cur = cur->next){
		if (cur->name == v)
			return (cur);
	}
	return (nil);
}

int	main(void)
{
	init();
	string v;
	cin >> v;
	Node* del = get_node(v);
	if (del == nil)
	 cout << "\"" << v << "\" :" << "not found" << endl;
	del->prev->next = del->next;
	del->next->prev = del->prev;
	delete del;
}
