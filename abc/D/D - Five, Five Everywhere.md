# D - Five, Five Everywhere

No	: 096  
url	: https://atcoder.jp/contests/abc096/tasks/abc096_d  
tag	: [[整数問題]] [[剰余]] [[構築]]  #ABC #cyan 

### idea
- どの異なる５つを選んでも合成数となるパターンを探す．
- ５で割った余りが等しい数を列挙すれば，和が必ず５の倍数となる．
- 実験してみると，55555以下の素数で余りが1,2,3,4のものはどれも1400個以上あった．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  auto is_prime=prime_number(55556);
  vvi ans(5);

  rep(i,55556) if(is_prime[i]) ans[i%5].push_back(i);

  rep(i,n) cout<<ans[1][i]<<endl;
}
```