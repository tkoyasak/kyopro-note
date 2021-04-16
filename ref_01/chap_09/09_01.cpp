// スタックとキューを連結リストを用いて実現

#include <iostream>
using namespace std;

// 連結リストの各ノードを表す構造体
struct	Node{
	Node *prev, *next;
	int value;
	Node(int value_ = NULL):
	prev(NULL), next(NULL), value(value_){}
};

// 番兵を表すノード
Node *head;
Node *tail;

// 初期化
void	init(){
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
}

// push
void	push(Node *n){
	n->prev = tail->prev;
	tail->prev->next = n;
	tail->prev = n;
	n->next = tail;
}

// stack 最後にpushされたnodeを取り出す
int	stack(void){
	int s = tail->prev->value;
	tail->prev->prev->next = tail;
	tail->prev = tail->prev->prev;
	return s;
}

// queue 最初にpushされたnodeを取り出す
int queue(void){
	int q = head->next->value;
	head->next->next->prev = head;
	head->next = head->next->next;
	return q;
}
