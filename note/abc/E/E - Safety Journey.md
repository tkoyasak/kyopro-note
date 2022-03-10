# E - Safety Journey

No	: 212  
url	: https://atcoder.jp/contests/abc212/tasks/abc212_e  
com	: https://youtu.be/hI8xC_1ZBf8  
tag	: [[動的計画法]]  #ABC #cyan #解説AC  

### idea
- 制約は次の通り．
	- $2 \le N \le 5000$
	- $0 \le M \le \min(\frac{N(N-1)}{2},5000)$
	- $2 \le K \le 5000$
- $\text{dp}[d][v] \coloneqq$ $d$ 日間の旅が終了して，最後に都市 $v$ にいる旅の組み合わせ数，と定義する．
- 各都市から移動可能な都市へ遷移するとすると $\mathcal{O}(N^2)$ となり，間に合わない．
- 使えない辺数に着目すると，$M$ 本なので $\mathcal{O}(K \times M)$ で済む．
- 貰うDPとして考えると，遷移は次の通り．
$$\begin{align} \text{dp}[d+1][v]&= \sum_{\mathclap{u \in v\text{の隣接頂点}}}\text{dp}[d][u] \\&= \sum_{\mathclap{u \in \text{全頂点}}}\text{dp}[d][u] - \sum_{\mathclap{u \in v\text{の非隣接頂点}}}\text{dp}[d][u] \end{align}$$
- 計算量は均しで $\mathcal{O}(K \times (N+M))$．

### code
```cpp
int	main(void)
{
  int n,m,k; cin>>n>>m>>k;
  vvi g(n);
  rep(m) {
    int a,b; cin>>a>>b; a--,b--;
    g[a].pb(b); g[b].pb(a);
  }

  vm dp(n);
  dp[0]=1;
  rep(k) {
    vm t(n); swap(dp,t);
    mint sum=0;
    rep(u,n) sum+=t[u];
    rep(v,n) {
      dp[v]=sum-t[v];
      fore(u,g[v]) dp[v]-=t[u];
    }
  }

  cout<<dp[0].val()<<endl;
}
```