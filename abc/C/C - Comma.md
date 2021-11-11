# C - Comma

No	: 195  
url	: https://atcoder.jp/contests/abc195/tasks/abc195_c  
tag	: [[全探索]]  #ABC #gray

### idea
- $\lfloor L,R)$ の $L,R$ を10倍していけば，すべての桁数の場合を考えることができる．
-  `min`/`max` を使って片方を0にすることで，閾値を設定することができる．

### code
```cpp
int	main(void)
{
  ll n; cin>>n;
  ll cma=0,l=1,r=10;
  ll ans=0;

  rep(i,16) {
    if(r<=n) ans+=(r-l)*cma;
    else if(l<=n&&n<r) ans+=(n-l+1)*cma;
    l*=10;
    r*=10;
    if(i%3==2) cma++;
  }

  cout<<ans<<endl;
}
```

```cpp
int	main(void)
{
  ll n; cin>>n;
  ll ans=0;

  ans+=max(0ll,n-999);
  ans+=max(0ll,n-999'999);
  ans+=max(0ll,n-999'999'999);
  ans+=max(0ll,n-999'999'999'999);
  ans+=max(0ll,n-999'999'999'999'999);

  cout<<ans<<endl;
}
```