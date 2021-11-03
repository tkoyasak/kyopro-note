# B - Multiplication 2

No	: 169  
url	: https://atcoder.jp/contests/abc169/tasks/abc169_b  
tag	: [[整数判定]]  #ABC #gray

### idea

### code
```cpp
int	main(void)
{
  const ll INF=1e18;
  ll n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  __int128_t ans=1;

  rep(i,n) {
    if(a[i]==0) {
      cout<<0<<endl; return 0;
    }
  }
  rep(i,n) {
    ans*=a[i];
    if(ans>INF) {
      cout<<-1<<endl; return 0;
    }
  }

  cout<<(ll)ans<<endl;
}
```