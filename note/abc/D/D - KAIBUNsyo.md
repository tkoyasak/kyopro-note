# D - KAIBUNsyo

No	: 206  
url	: https://atcoder.jp/contests/abc206/tasks/abc206_d  
tag	: [[UnionFind]]  #ABC #green

### idea
- すべての $i$ $(1 \le i \le N)$ について，もし $A_i \neq A_{N+1-i}$ ならば，$A_i$ と $A_{N+1-i}$ は最終的に同じ整数に置換されていなければならない．
- このことを無向グラフの頂点 $A_i,A_{N+1-i}$ を結ぶ辺として表す．
- グラフの同じ連結成分に属する頂点は，最終的にすべて同じ整数に置換されていなければならない．
- したがって，求める最小回数は各連結成分について，(連結成分のサイズ)$-1$ となる．
- 計算量は $\mathcal{O}(M+ \alpha (N))$．

### code
```cpp
int	main(void)
{
  const int M=200100;
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  UnionFind uf(M);
  int ans=0;

  rep(i,n/2) uf.unite(a[i],a[n-i-1]);
  rep(i,M) if(uf.root(i)==i) ans+=uf.size(i)-1;

  cout<<ans<<endl;
}
```