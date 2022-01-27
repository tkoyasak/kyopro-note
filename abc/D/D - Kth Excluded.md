# D - Kth Excluded

No	: 205  
url	: https://atcoder.jp/contests/abc205/tasks/abc205_d  
tag	: [[二分探索]]  #ABC #brown

### idea
- 数列 $A=(A_1,A_2, \ldots ,A_N)$ のいずれとも異なる正整数を良い整数と呼ぶことにする．
- $A_i$ 未満の整数で良い整数は $A_i-(i+1)$ 個あるので，$A_i-i$ 番目の良い整数は $A_i+1$ となる．
- $K$ がどの要素間にあるかを二分探索することで，$K$ 番目の良い整数を求めることができる．
- 計算量は $\mathcal{O}(N+Q \log N)$．

### code
```cpp
int	main(void)
{
  int n,q; cin>>n>>q;
  vll a(n); rep(i,n) cin>>a[i];
  map<ll,ll> mp;

  mp[0]=0;
  rep(i,n) mp[a[i]-i]=a[i]+1;
  rep(i,q) {
    ll k; cin>>k;
    auto it=mp.upper_bound(k);
    --it;
    cout<<it->second+(k-it->first)<<endl;
  }
}
```