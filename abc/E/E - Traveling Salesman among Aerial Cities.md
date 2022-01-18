# E - Traveling Salesman among Aerial Cities

No	: 180  
url	: https://atcoder.jp/contests/abc180/tasks/abc180_e  
tag	: [[動的計画法]] [[巡回セールスマン問題]]  #ABC #cyan #解説AC 

### idea
- 巡回セールスマン問題 (TSP) といわれる典型問題．
- 都市間の移動コストについて三角不等式が成り立つので，ある都市から次の都市へ移動するとき別の都市を経由する必要はない．各都市をちょうど一度ずつ訪れる場合について考えればいい．
- これが成り立たない場合は，フロイド･ワーシャル法などを用いて各都市間の最小コストを求める必要がある．
- すべての訪問順を探索する場合，$O(N! \times N)$ かかるので，制約を満たせない．
- $\text{dp}[i][S] \coloneqq$ 現在地が都市 $i$ で訪問済みの都市の集合が $S$ であるときのコストの最小値，と定義する．次のように更新していく．
	$$\text{dp}[j][S\cup\{j\}] \leftarrow \text{dp}[i][S]+\text{dist}[i][j]$$

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  const int N=1<<n;
  vi x(n),y(n),z(n); rep(i,n) cin>>x[i]>>y[i]>>z[i];
  vvi dp(n,vi(N,inf)),dist(n,vi(n));

  // 都市間の移動コスト i->j
  rep(i,n) rep(j,n) {
    dist[i][j]=abs(x[j]-x[i])+abs(y[j]-y[i])+max(0,z[j]-z[i]);
  }

  // 出発は都市 0
  rep(j,n) dp[j][1<<j]=dist[0][j];
  // DP
  rep(s,N) rep(i,n) if(s>>i&1) {
    rep(j,n) if(~s>>j&1) {
      chmin(dp[j][s|1<<j],dp[i][s]+dist[i][j]);
    }
  }

  cout<<dp[0][N-1]<<endl;
}
```