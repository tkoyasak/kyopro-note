# A - One Card Poker

No	: 54  
url	: https://atcoder.jp/contests/abc054/tasks/abc054_a  
tag	: [[整数判定]]  #ABC #gray

### idea
- 2 -> 3 -> ･･･ -> 13 -> 1 の順で強いので，１が入力されたら13を足すと良い．

### code
```cpp
int	main(void)
{
	int a,b;
	cin>>a>>b;
	if (a==1) a+=13;
	if (b==1) b+=13;
	if (a==b) cout<<"Draw\n";
	else if (a>b) cout<<"Alice\n";
	else cout<<"Bob\n";
}
```