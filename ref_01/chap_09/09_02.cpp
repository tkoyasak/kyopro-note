// 逆ポーランド記法

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

stack<int> st;

void func(string c){
	int a, b;
	b = st.top();
	st.pop();
	a = st.top();
	st.pop();
	if (c == "+") st.push(a + b);
	if (c == "-") st.push(a - b);
	if (c == "*") st.push(a * b);
	if (c == "/") st.push(a / b);
	if (c == "%") st.push(a % b);
}

int	main(void){
	// split
	string str, s;
	vector<string> v;
	getline(cin, str);
	stringstream sstr{str};
	while (getline(sstr, s, ' '))
		v.push_back(s);

	for (int i = 0; i < (int)v.size(); ++i){
		if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/" || v[i] == "%")
			func(v[i]);
		else{
			int flg = (int)stol(v[i]);
			st.push(flg);
		}
	}
	cout << st.top() << endl;
}
