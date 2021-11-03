# A - +-x

No	: 137  
url	: https://atcoder.jp/contests/abc137/tasks/abc137_a  
tag	: [[整数判定]]  #ABC #gray

### idea
- `{}`で与えてあげると，複数個の比較ができる．

### code
```cpp
int	main(void)
{
  int a,b;
  cin>>a>>b;

  cout<<max({a+b,a-b,a*b})<<endl;
}
```