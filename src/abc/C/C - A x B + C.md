# C - A x B + C

No	: 179  
url	: https://atcoder.jp/contests/abc179/tasks/abc179_c  
tag	: [[整数判定]]  #ABC #gray

### idea
- $A \times B \lt N$ を満たす正整数の組 $(A,B)$ に対し，$A \times B + C = N$ となる正整数 $C$ は一意に定まる．
- $A$ を固定したとき，$B$ として考えられる値は $\lfloor \frac{N-1}{A} \rfloor$ 個ある．

### code
```cpp
int	main(void)
{
  ll n; cin>>n;
  ll ans=0;

  reps(i,1,n) ans+=(n-1)/i;

  cout<<ans<<endl;
}
```