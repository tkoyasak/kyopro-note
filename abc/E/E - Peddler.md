# E - Peddler

No	: 188  
url	: https://atcoder.jp/contests/abc188/tasks/abc188_e  
tag	: [[動的計画法]] [[DAG]]  #ABC #green

### idea
- $X_i \lt Y_i$ のため，グラフは DAG(Directed Acyclic Graph) である．
- $\text{dp}[i] \coloneqq$ 街 $i$ に到達できる街 (街 $i$ 自身は含まない) における支出の最小値，と定義する．
- $A_i-\text{dp}[i]$ の最大値が答えとなる．
- 計算量は $O(N+M)$．

### code
```cpp
int	main(void)
{
  const int inf=2e9+20;
  int n,m; cin>>n>>m;
  vi a(n); rep(i,n) cin>>a[i];
  vvi g(n);
  rep(i,m) {
    int x,y; cin>>x>>y; x--; y--;
    g[x].push_back(y);
  }
  vi dp(n,inf);
  int ans=-inf;

  rep(i,n) {
    chmax(ans,a[i]-dp[i]);
    fore(j,g[i]) chmin(dp[j],min(dp[i],a[i]));
  }

  cout<<ans<<endl;
}
```