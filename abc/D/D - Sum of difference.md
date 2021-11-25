# D - Sum of difference

No	: 186  
url	: https://atcoder.jp/contests/abc186/tasks/abc186_d  
tag	: [[累積和]]  #ABC #brown

### idea
- 入力をソートして$A_1 \le \ldots \le A_N$ とすると，$i<j$ に対して $|A_i-A_j|=A_j-A_i$ となる．
- 各 $i$ について $\sum_{j=i+1}^{N} |A_i - A_j| = (\sum_{j=i+1}^{N} A_j)-(N-i)A_i$ となり，あらかじめ累積和を計算しておくことで各々 $O(1)$ で求めることができる．
- 計算量は，$O(NlogN)$ ．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  ll ans=0,w=0;

  sort(all(a));
  rep(i,n) {
    ans+=(ll)a[i]*i-w;
    w+=a[i];
  }

  cout<<ans<<endl;
}
```