# D - Not Divisible

No	: 170  
url	: https://atcoder.jp/contests/abc170/tasks/abc170_d  
tag	: [[整数問題]]  #ABC #green

### idea
- $\text{cnt}[x] \coloneqq$ 数列 $A$ の中に $x$ の約数が何個含まれるか，と定義する．
- $A_i$ に重複がある場合は，$\text{cnt}[A_i]$ を $2$ にすることで適切に処理できる．
- 計算量は $\sum_{i=1}^{M} \frac{M}{i}=O(M \log M)$．これは調和級数の計算量である．

### code
```cpp
int	main(void)
{
  const int M=1001001;
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  vi cnt(M,0);
  int ans=0;

  fore(x,a) {
    if(cnt[x]) cnt[x]=2;
    else for(int i=x;i<M;i+=x) cnt[i]++;
  }
  fore(x,a) if(cnt[x]==1) ans++;

  cout<<ans<<endl;
}
```