# C - Bridge

No	: 075  
url	: https://atcoder.jp/contests/abc075/tasks/abc075_c  
tag	: [[深さ優先探索]] [[LowLink]]  #ABC #green

### idea
- DFSをしたとき，後退辺 (DFSで通らなかった辺) は橋となり得ない．
- $\text{ord}[v] \coloneqq$ 頂点 $v$ を訪れた順番．
- $\text{low}[v] \coloneqq$ 頂点 $v$ から「DFS-Treeの根->葉」or「後退辺を高々１回」に進むことによってたどり着ける頂点 $w$ について $\text{ord}[w]$ の最小値．
- 「 辺 $(u,v)$ が橋である 」 $\Leftrightarrow$
	- 「 $\text{ord}[u] \lt \text{low}[v]$ 」
- 「 点 $u$ が間接点である 」$\Leftrightarrow$
	- 「 $u$ が根であるとき，２個以上の子を持つ 」
	- 「 $u$ が根でないとき，$u$ のある子 $v$ について $\text{ord}[u] \le \text{low}[v]$ を満たす 」
- 計算量は $O(N+M)$．

### code
```cpp
struct LowLink {
  vp brs;

  vi seen, ord, low;
  void	dfs(const graph& g, int v, int p=-1) {
    static int time=0;

    seen[v]=1;
    low[v]=ord[v]=time++;
    fore(c,g[v]) {
      if(seen[c]) {
        if(c!=p) chmin(low[v],ord[c]);
        continue;
      }
      dfs(g,c,v);
      chmin(low[v],low[c]);
      if(low[c]>ord[v]) brs.emplace_back(v,c);
    }
  }

  void	solve(const graph& g) {
    int n=g.size();

    seen.assign(n,0); ord.assign(n,0); low.assign(n,0);
    brs.clear();
    rep(i,n) if (!seen[i]) dfs(g,i);
  }
};

int	main(void)
{
  int n,m; cin>>n>>m;
  graph g(n);
  rep(i,m) {
    int a,b; cin>>a>>b;
    a--; b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  LowLink ll;
  ll.solve(g);

  cout<<ll.brs.size()<<endl;
}
```