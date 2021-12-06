# C - HSI

No	: 078  
url	: https://atcoder.jp/contests/abc078/tasks/arc085_a  
tag	: [[確率]]  #ABC #brown

### idea
- [解説記事 @drken](https://drken1215.hatenablog.com/entry/2019/03/23/175300)
- 有効なカードを引く確率が $p$ のとき，有効なカードが来るまでカードを引き続ける回数の期待値は $\dfrac{1}{p}$ となる．

### code
```cpp
int	main(void)
{
  ll n,m; cin>>n>>m;
  ll sub=1LL<<m;
  ll time=1900*m+100*(n-m);

  cout<<time*sub<<endl;
}
```