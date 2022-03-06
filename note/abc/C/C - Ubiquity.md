# C - Ubiquity

No	: 178  
url	: https://atcoder.jp/contests/abc178/tasks/abc178_c  
tag	: [[包除原理]]  #ABC #brown

### idea
- $0 \le A_i \le 9$ なる長さ $N$ の整数列 $\{A\}$ 全体について考える．
- $\{A\}$ 全体は $10^N$  
- $A_i=0$ なる $i$ が存在しないような $\{A\}$ は $9^N$ 通り．
- $A_i=9$ なる $i$ が存在しないような $\{A\}$ は $9^N$ 通り．
- $A_i=0$ なる $i$ と $A_i=9$ なる $i$ が存在しないような $\{A\}$ は $8^N$ 通り．
- $A_i=0$ なる $i$ と $A_i=9$ なる $i$ がともに存在するような $\{A\}$ は $10^N-9^N-9^N+8^N$ 通り．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  ll ans;

  auto f=[&](ll x, ll y) {
    ll res=1;
    rep(i,y) (res*=x)%=mod;
    return res;
  };

  ans=f(10,n)-f(9,n)-f(9,n)+f(8,n);
  ans%=mod;
  ans=(ans+mod)%mod;

  cout<<ans<<endl;
}
```