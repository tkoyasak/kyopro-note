# E - Just one

No	: 226  
url	: https://atcoder.jp/contests/abc226/tasks/abc226_e  
tag	: [[グラフ]] [[UnionFind]]  #ABC #cyan

### idea
- 各頂点から辺が１本ずつ出ているので，「頂点数 $\neq$ 辺数」の場合は達成不可能．
- サイクル外は端から自動的に向きが決まるので，各サイクル内で頂点数と辺数が一致していれば条件を満たす．
- サイクルの向きは２通りあるので，求める答えは $2^{\text{サイクルの個数}}$ となる．
- 各頂点の出次数がちょうど１である有向グラフのことを Functional Graph という．
- 頂点数と辺数が一致するグラフを Pseudo-Tree という．

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  UnionFind uf(n);
  vpii uv(m);
  vi edges(n,0);
  mint ans=1;

  rep(i,m) {
    int u,v; cin>>u>>v; u--; v--;
    uv[i]={u,v};
    uf.unite(u,v);
  }
  for(auto& [u,v]:uv) edges[uf.root(u)]++;
  rep(i,n) {
    if(i!=uf.root(i)) continue;
    if(uf.size(i)==edges[i]) ans*=2;
    else ans=0;
  }

  cout<<ans<<endl;
}
```