# A - Poor

No	: 155  
url	: https://atcoder.jp/contests/abc155/tasks/abc155_a  
tag	: [[整数判定]]  #ABC #gray 

### idea
- 数の種類数をカウントするには，`set`を用いると良い．

### code
```cpp
int	main(void)
{
  set<int> s;
  rep(i,3)) {
    int x;
    cin>>x;
    s.insert(x);
  }

  cout<<(s.size()==2?"Yes":"No")<<endl;
}
```