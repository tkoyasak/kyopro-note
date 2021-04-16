// 単方向リストにおいて，特定のノードvを削除する方法
// 最大でO(N)

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

struct Node *get_prev_node(string s){
	Node* cur = nil;
	for (; cur->next!= nil; cur = cur->next){
		if (cur->next->name == s)
			return (cur);
	}
	return (NULL);
}

int	main(void)
{
	init();
	string s;
	cin >> s;
	Node* prev_del = get_prev_node(s);
	if (prev_del == NULL)
	 cout << "\"" << s << "\" : not found" << endl;
	else{
		prev_del->next = prev_del->next->next;
		delete prev_del->next;
	}
}
