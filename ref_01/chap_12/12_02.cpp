#include <iostream>
#include <vector>
using namespace std;

int tmp_num;

struct	Shop{
	Shop *next;
	int prc, nbr;
	Shop(int prc_ = 0, int nbr_ = 0):
	next(NULL), prc(prc_), nbr(nbr_){}
};

// 番兵を表すノード
Shop *head;
Shop *tail;

// 初期化
void	init(){
	head = new Shop();
	tail = new Shop();
	tail->next = head;
	tmp_num = 0;
}

// push
void	push(Shop *s, Shop *p = tail){
	s->next = p->next;
	p->next = s;
}

// sort
void	sort(void){
	for (Shop *tmp = tail; tmp->next->next != head;){
		if(tmp->next->next->prc < tmp->next->prc){
			Shop *s = tmp->next, *ss = tmp->next->next;
			s->next = ss->next;
			ss->next = s;
			tmp->next = ss;
			tmp = tail;
		}
		tmp = tmp->next;
	}
}

void	getPrice(int M){
	int sum_price = 0, sum_nbr = 0;
	Shop *tmp = tail->next;
	for (; tmp != head; tmp = tmp->next){
		if (tmp->nbr + sum_nbr >= M){
			sum_price += ((M - sum_nbr) * tmp->prc);
			break;
		}
		else{
			sum_nbr += tmp->nbr;
			sum_price += tmp->nbr * tmp->prc;
		}
	}
	if (tmp == head)
		cout << "Energy Drinks are not enough." << endl;
	else
		cout << "You could buy for " << sum_price << " yen." << endl;
}

int	main(void){
	int N, M;
	cin >> N >> M;
	vector<int> A(N), B(N);
	init();

	for (int i = 0; i < N; ++i){
		++tmp_num;
		cin >> A[i] >> B[i];
		Shop *shop = new Shop(A[i], B[i]);
		push(shop);
		sort();
	}

	getPrice(M);
}
