# D - Enough Array

No	: 130  
url	: https://atcoder.jp/contests/abc130/tasks/abc130_d  
tag	: [[尺取り法]]  #ABC #green

### idea
- 部分列の総和が $K$ 未満である限り $r$ を右に更新していく．
- $r$ が左に更新されることはない．

### code
```cpp
int	main(void)
{
  ll n,k; cin>>n>>k;
  vi a(n); rep(i,n) cin>>a[i];
  int r=0;
  ll ans=0,cnt=0;

  rep(l,n) {
    while(r<n && cnt+a[r]<k) {
      cnt+=a[r];
      ++r;
    }
    ans+=n-r;
    cnt-=a[l];
  }

  cout<<ans<<endl;
}
```