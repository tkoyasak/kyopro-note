# C - Not Equal

No	: 209  
url	: https://atcoder.jp/contests/abc209/tasks/abc209_c  
tag	: [[組み合わせ]]  #ABC #gray

### idea
- 条件を見直す
	- $1 \le A_i \le C_i$ に数 $A_i$ を収める必要がある．
	- 数はどの１つもかぶらせない．
- 数を指定する順番は指定されていないので，整数列 $C$ をソートすると先頭から順に数を決めていくことができる．
- 数 $A_i$ は，$1 \le A_i \le C_i$ かつ どの $A_k(1 \le k \lt i)$ とも異なる数である．
- よって組み合わせは， $C_i - i$ 通りあることがわかる．
- これを $n$ まで累積をとれば答えとなる．



### code
```cpp
int	main(void)
{
  ll n; cin>>n;
  vll c(n); rep(i,n) cin>>c[i];
  ll ans=1,mod=1e9+7;

  sort(all(c));
  rep(i,n) ans=ans*(c[i]-i)%mod;
  cout<<ans<<endl;
}
```