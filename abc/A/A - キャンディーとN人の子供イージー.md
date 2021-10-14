# A - キャンディーとN人の子供イージー

No	: 43  
url	: https://atcoder.jp/contests/abc043/tasks/abc043_a  
tag	: [[整数判定]]  #ABC #gray

### idea
- $n!=\frac{n(n+1)}{2}$ を利用する．

### code
```cpp
int	main(void)
{
	int n;
	cin>>n;
	cout<<n*(N+1)/2<<endl;
}
```