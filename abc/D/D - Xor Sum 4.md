# D - Xor Sum 4

No	: 147  
url	: https://atcoder.jp/contests/abc147/tasks/abc147_d  
tag	: [[XOR]] [[Bit]] [[整数問題]]  #ABC #cyan #解説AC 

### idea
- XORは「**角桁ごとに考える**」というのが定石．
- その視点で問題は次のように考えることができる．
	- $\sum_{i=1}^{N-1}\sum_{j=i+1}^{N}(A_i\text{ XOR }A_j)$ の $N(N+1)/2$ 個の値のうち $d$ 桁目が $1$ であるものの個数を $S_d$とする．
	- このとき答えに $S_d \times 2^d$ を加算する．
- 問題は「$N(N+1)/2$ 個の値のうち，$d$ 桁目が $1$ であるものの個数 $S_d$」 を求めることに帰着された．
- XORの定義から，数列 $A$ のうち $d$ 桁目が $1$ であるものの個数を $p$，$0$ であるものの個数を $q$ とすると，$S_d=p \times q$ となる． 

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vl a(n); rep(i,n) cin>>a[i];
  mint ans=0;

  rep(d,60) {
    ll mask=1LL<<d;
    int p=0,q=0;
    rep(i,n) {
      if(a[i]&mask) p++;
      else q++;
    }
    ans+=mint(mask)*p*q;
  }

  cout<<ans<<endl;
}
```