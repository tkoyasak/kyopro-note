# C - Buy an Integer

No	: 146
url	: https://atcoder.jp/contests/abc146/tasks/abc146_c  
tag	: [[二分探索]]  #ABC #brown

### idea
- $A \times N + B \times d(N)$	は単調増加なので，二分探索できる．
- $[1,10^9]$ の範囲なので，計算量は $\mathcal{O}(\log 10^9)$
- 桁数は $[1,9]$ の範囲なので，ループを回して最大値を求めても良い．

### code
```cpp
int	main(void)
{
  ll a,b,x; cin>>a>>b>>x;
  ll l=0,r=1e9+1;

  auto digit=[&](ll n) {
    return to_string(n).size();
  };
  auto f=[&](ll n) {
    return a*n+b*digit(n);
  };

  while(l+1<r) {
    ll n=(l+r)/2;
    if(f(n)<=x) l=n;
    else r=n;
  }

  cout<<l<<endl;
}
```

```cpp
int	main(void)
{
  ll a,b,x; cin>>a>>b>>x;
  ll ans=0;

  auto f=[&](ll d) {
    return a*pow(10,d)+b*(d+1);
  };

  rep(d,10) {
    if(x<f(d)) break;
    ll r=x-b*(d+1);
    ll p=pow(10,d+1);
    if(d==9) chmax(ans,min(r/a,p/10));
    else chmax(ans,min(r/a,p-1));
  }

  cout<<ans<<endl;
}
```