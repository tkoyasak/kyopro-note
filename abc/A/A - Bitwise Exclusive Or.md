# A - Bitwise Exclusive Or

No	: 213  
url	: https://atcoder.jp/contests/abc213/tasks/abc213_a  
tag	: [[bit]]  #ABC #gray

### idea
- $x \land x=0$ を利用している．

### code
```cpp
int	main(void)
{
	int a,b;
	cin>>a>>b;
	
	cout<<(a^b)<<endl;
}
```