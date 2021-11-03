# A - Chinchirorin

No	: 203  
url	: https://atcoder.jp/contests/abc203/tasks/abc203_a  
tag	: [[bit]]  #ABC  #gray

### idea
- $x \land x=0$ を利用している．

### code
```cpp
int	main(void)
{
  int a,b,c;
  cin>>a>>b>>c;

  if (a!=b&&b!=c)
    cout<<0<<endl;
  else
    cout<<(a^b^c)<<endl;
}
```