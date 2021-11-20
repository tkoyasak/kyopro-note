# A - Grouping

No	: 062  
url	: https://atcoder.jp/contests/abc062/tasks/abc062_a  
tag	: [[整数判定]]  #ABC #gray

### idea
- 配列またはマップに，条件をセットすることで判定が簡単になる．

### code
```cpp
int	main(void)
{
  int a[]={0,1,3,1,2,1,2,1,1,2,1,2,1};
  int x,y;
  cin>>x>>y;

  YesNo(a[x]==a[y]);
}
```

```cpp
int	main(void)
{
  int x,y;
  cin>>x>>y;
  map<int,int> a;

  a[1]=a[3]=a[5]=a[7]=a[8]=a[10]=a[12]=1;
  a[4]=a[6]=a[9]=a[11]=2;
  a[2]=3;

  YesNo(a[x]==a[y]);
}
```
