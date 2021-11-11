# C - Distribution

No	: 214  
url	: https://atcoder.jp/contests/abc214/tasks/abc214_c  
tag	: [[動的計画法]]  #ABC #gray

### idea
- まず，円周ではなく，数直線で $[1,n]$ の範囲を考える．
  - `dp[i]` := $i$ 番目に宝石がくる最短時間
  - $dp[0]=t[0]$，$dp[i]=min(dp[i-1]+t[i-1],t[i])$ となる．
- 円周を考えると，$n-2 \rightarrow n-1 \rightarrow 0 \rightarrow 1$ となり，$dp[0]$ が更新される場合がある．
- したがって，２周目の更新を行う．しかし，３周目以降の更新の必要はない．
- 計算量は，$O(N \times 2)$ となる．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vi s(n),t(n);
  rep(i,n) cin>>s[i];
  rep(i,n) cin>>t[i];

  rep(i,n*2) chmin(t[(i+1)%n],t[i%n]+s[i%n]);

  rep(i,n) cout<<t[i]<<endl;
}
```