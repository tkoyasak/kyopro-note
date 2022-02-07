# Traveling Salesman Problem

No	: DPL - 2A  
url	: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_2_A  
tag	: [[動的計画法]] [[巡回セールスマン問題]]  #AOJ #black 

### idea
- 求めるのは閉路なので．スタートを頂点 $0$ と定めていい．
- 初期化において頂点 $0$ を訪問済みとし，DP後の最小値を求めるときに，頂点 $v$ から頂点 $0$ までのコストを加算する．

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  const int N=1<<n;
  vvi dist(n,vi(n,inf));
  rep(i,m) {
    int s,t,c; cin>>s>>t>>c;
    dist[s][t]=c;
  }
  vvi dp(n,vi(N,inf));
  int ans=inf;

  // 頂点０にいて頂点０のみを訪問済みとする
  dp[0][1]=0;

  rep(s,N) rep(i,n) if(s>>i&1) {
    rep(j,n) if(~s>>j&1) {
      chmin(dp[j][s|1<<j],dp[i][s]+dist[i][j]);
    }
  }
  rep(i,n) chmin(ans,dp[i][N-1]+dist[i][0]);

  if(ans==inf) cout<<-1<<endl;
  else cout<<ans<<endl;
}
```