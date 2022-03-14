# E - Amusement Park

No	: 216  
url	: https://atcoder.jp/contests/abc216/tasks/abc216_e  
com	: https://youtu.be/Tgd_zLfRZOQ?t=3138  
tag	: [[二分探索]]  #ABC #green 

### idea
- $f(X) \coloneqq$ 楽しさの最大値を $X$ 以下にするまでにかかる回数．と定義する．
- $M \coloneqq f(X) \lt K \le f(X-1)$ を満たす最小の $X$，は二分探索で求めることができる．
- このとき求める答えは，$\sum_{i=1}^{N} {\sum_{j=M+1}^{A_i} j} + M(K-f(M))$．
- 計算量は $\mathcal{O}(N \log \max(A))$．

### code
```cpp
int main(void)
{
  int n,k; cin>>n>>k;
  vi a(n); fore(i,a) cin>>i;

  auto f=[&](ll x) {
    ll cnt=0;
    fore(i,a) cnt+=max(0LL,i-x);
    return cnt;
  };

  ll wa=-1,ac=2e9;
  while(wa+1<ac) {
    int m=(wa+ac)/2;
    if(f(m)<k) ac=m;
    else wa=m;
  }

  ll ans=0;
  fore(i,a) ans+=asum(ac+1,i);
  ans+=ac*(k-f(ac));
  cout<<ans<<endl;
}
```