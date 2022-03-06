# C - 正直者の高橋くん

No	: 021  
url	: https://atcoder.jp/contests/abc021/tasks/abc021_c  
tag	: [[幅優先探索]] [[最短経路問題]] [[動的計画法]]  #ABC #cyan #解説AC 

### idea
- [ABC211-D](https://atcoder.jp/contests/abc211/tasks/abc211_d) と同じ問題！
- [幅優先探索について](https://youtu.be/I120G6rwz5A)
- 最短経路を求める幅優先探索では，最短距離を表す配列を $\text{dist}$ として用意する．
  - $v$ から遷移できる $v'$ に対して次を行う．
    - $v'$ に未到達なら，$\text{dist}[v']=\text{dist}[v]+1$ に更新．
    - そうでないなら，何もしない．
- このとき，最短経路の数を表す配列 $\text{dp}$ を新たに用意することで，次のように更新できる．
  - $v$ から遷移できる $v'$ に対して次を行う．
    - $v'$ に未到達なら，$\text{dist}[v']=\text{dist}[v]+1$ に更新し，$\text{dp}[v']$ に $\text{dp}[v]$ を代入する．
    - $v'$ に到達済かつ，$\text{dist}[v']=\text{dist}[v]+1$ ならば，$\text{dp}[v']$ に $\text{dp}[v]$ を加算する．
    - そうでないなら，何もしない．
- 計算量は $\mathcal{O}(N+M)$．

### code
```cpp
int	main(void)
{
  int n,a,b,m; cin>>n>>a>>b>>m,a--,b--;
  vvi g(n);
  rep(i,m) {
    int u,v; cin>>u>>v,u--,v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vi dist(n,-1);
  vector<mint> dp(n,0);
  queue<int> q;

  dist[a]=0;
  q.push(a);
  dp[a]=1;
  while(!q.empty()) {
    int u=q.front(); q.pop();
    fore(to,g[u]) {
      if(dist[to]==-1) {
        q.push(to);
        dist[to]=dist[u]+1;
      }
      if(dist[to]==dist[u]+1) {
        dp[to]+=dp[u];
      }
    }
  }

  cout<<dp[b]<<endl;
}
```