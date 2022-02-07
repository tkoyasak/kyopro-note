# D - Sum of Maximum Weights

No	: 214  
url	: https://atcoder.jp/contests/abc214/tasks/abc214_d  
com	: https://youtu.be/RCB7EZaddEQ  
tag	: [[UnionFind]] [[木構造]]  #ABC #cyan #解説AC 

### idea
- 頂点ではなく，辺に着目する．
- 最短経路に辺 $i$ が含まれる頂点 $u,v$ の組は，辺 $i$ を挟んで $u_i$ 側の連結成分と $v_i$ 側の連結成分の組み合わせすべてになる．
- $f(u,v)$ を求めるために，「辺 $i$ が辺の重みの最大値となる頂点の組」がいくつあるかを考える．
- 「最短経路で辺 $i$ を通って，かつ，よりコストが大きい辺を通らない頂点の組の個数」
		$\Rightarrow$ 「重み $w_i$ 以下の辺だけ通れる状態で，最短経路で辺 $i$ を通る頂点の組の個数」となる．
- Union-Find を用いて，クラスカル法のように連結するたびに，$f(u,v)$ が最大となる個数分だけ足していく．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vector<tuple<ll,int,int>> es;
  rep(n-1) {
    int u,v,w; cin>>u>>v>>w; u--,v--;
    es.emplace_back(w,u,v);
  }
  UnionFind uf(n);
  ll ans=0;

  srt(es);
  for(auto [w,u,v]:es) {
    ans+=w*uf.size(u)*uf.size(v);
    uf.unite(u,v);
  }

  cout<<ans<<endl;
}
```