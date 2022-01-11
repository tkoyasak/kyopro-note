# D - Count Interval

No	: 233  
url	: https://atcoder.jp/contests/abc233/tasks/abc233_d  
tag	: [[全探索]] [[数え上げ問題]]  #ABC #brown 

### idea
- $0 \le i \le N$ に対して $S_i＝\sum_{j=1}^{i} A_i$ と累積和をとると，問題は次のようになる．
> 以下の条件を満たす整数の組 $(l,r)$ はいくつあるか？
> - $1 \le l \le r \le N$
> - $S_r - S_{l-1} = K$
- これに基づいて $O(N^2)$ 解を考えると，次のようになる．
```cpp
  rep(r,n) rep(l,r+1) {
    if(S[r]-K==S[l-1]) ans++;
  }
```
- `std::map` を用いることで，２つ目のループを削除することができる．
- 計算量は $O(N \log N)$．


### code
```cpp
int	main(void)
{
  ll n,k; cin>>n>>k;
  vl a(n); rep(i,n) cin>>a[i];
  vl w(n+1); rep(i,n) w[i+1]=w[i]+a[i];
  map<ll,ll> mp;
  ll ans=0;

  reps(r,1,n+1) {
    mp[w[r-1]]++;
    ans+=mp[w[r]-k];
  }

  cout<<ans<<endl;
}
```