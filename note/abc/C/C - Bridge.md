# C - Bridge

No	: 075  
url	: https://atcoder.jp/contests/abc075/tasks/abc075_c  
tag	: [[UnionFind]] [[深さ優先探索]] [[LowLink]]  #ABC #green

### idea
##### Method 1 (UnionFind)
- 各辺 $e$ ごとに，辺 $e$ を除いた $M-1$ 本の辺からなるグラフを毎回生成する．
- このように生成したグラフが連結かどうかは Union-Find を用いて判定する．
- 計算量は $\mathcal{O}(M^2 \alpha (N))$．

##### Method 2 (LowLink)
- DFSをしたとき，後退辺 (DFSで通らなかった辺) は橋となり得ない．
- $\text{ord}[v] \coloneqq$ 頂点 $v$ を訪れた順番．
- $\text{low}[v] \coloneqq$ 頂点 $v$ から「DFS-Treeの根->葉」or「後退辺を高々１回」に進むことによってたどり着ける頂点 $w$ について $\text{ord}[w]$ の最小値．
- 「 辺 $(u,v)$ が橋である 」 $\Leftrightarrow$
	- 「 $\text{ord}[u] \lt \text{low}[v]$ 」
- 「 点 $u$ が間接点である 」$\Leftrightarrow$
	- 「 $u$ が根であるとき，２個以上の子を持つ 」
	- 「 $u$ が根でないとき，$u$ のある子 $v$ について $\text{ord}[u] \le \text{low}[v]$ を満たす 」
- 計算量は $\mathcal{O}(N+M)$．

### code
```cpp
// Method 1
int	main(void)

  int n,m; cin>>n>>m;
  vi a(m),b(m);
  rep(i,m) cin>>a[i]>>b[i],a[i]--,b[i]--;
  int ans=0;

  rep(e,m) {
    UnionFind uf(n);
    rep(i,m) if(i!=e) uf.unite(a[i],b[i]);
    int cnt=0;
    rep(v,n) if(uf.root(v)==v) cnt++;
    if(cnt>1) ans++;
  }

  cout<<ans<<endl;
}
```

```cpp
// Method 2
class LowLink {
 private:
  vi seen, ord, low;

 public:
  int brs;

  void	dfs(const vvi& g, int v, int p=-1) {
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
      if(low[c]>ord[v]) brs++;
    }
  }

  void	solve(const vvi& g) {
    int n=sz(g);

    seen.assign(n,0); ord.assign(n,0); low.assign(n,0);
    brs=0;
    rep(i,n) if (!seen[i]) dfs(g,i);
  }
};

int	main(void)
{
  int n,m; cin>>n>>m;
  vvi g(n);
  rep(i,m) {
    int a,b; cin>>a>>b; a--; b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  LowLink ll; ll.solve(g);

  cout<<ll.brs<<endl;
}
```