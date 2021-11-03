# B - Balance

No	: 129  
url	: https://atcoder.jp/contests/abc129/tasks/abc129_b  
tag	: [[整数判定]] [[累積和]]  #ABC #gray

### idea
- 累積和とすることで，`w[i]`を番号`i`以下の重りの重さとできる．

### code
```cpp
int	mian(void)
{
  ll n;
  cin>>n;
  vll w(n);
  rep(i,n) cin>>w[i];
  reps(i,1,n) w[i]+=w[i-1];
  ll ans=INF;

  rep(t,n-1) {
    ll s1=w[t];
    ll s2=w[n-1]-s1;
    chmin(ans,abs(s1-s2));
  }

  cout<<ans<<endl;
}
```