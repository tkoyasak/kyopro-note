# D - Number of Shortest paths

No	: 211  
url	: https://atcoder.jp/contests/abc211/tasks/abc211_d  
tag	: [[最短経路問題]] [[幅優先探索]] [[動的計画法]]  #ABC #brown

### idea
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
- 計算量は $O(N+M)$．

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  graph g(n);
  rep(i,m) {
    int a,b; cin>>a>>b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  queue<int> que;
  vi dist(n,-1);
  vi dp(n);

  que.push(0);
  dist[0]=0;
  dp[0]=1;
  while(que.size()) {
    int u=que.front();
    que.pop();
    fore(v,g[u]) {
      if(dist[v]==-1) {
        que.push(v);
        dist[v]=dist[u]+1;
      }
      if(dist[v]==dist[u]+1) {
        (dp[v]+=dp[u])%=mod;
      }
    }
  }

  cout<<dp[n-1]<<endl;
}
```