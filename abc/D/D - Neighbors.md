# D - Neighbors

No	: 231  
url	: https://atcoder.jp/contests/abc231/tasks/abc231_d  
tag	: [[UnionFind]]  #ABC #brown 

### idea
- 与えられたグラフがすべてパスグラフであるかどうかを判定する．
- パスグラフの条件 :
  - 次数が２以下
  - サイクルがない (木構造) -> UnionFindで判定
- 計算量は $O(N+M)$．

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  UnionFind uf(n);
  vi deg(n,0);
  bool ok=true;

  rep(i,m) {
    int a,b; cin>>a>>b; a--; b--;
    if(uf.same(a,b)) ok=false;
    uf.unite(a,b);
    deg[a]++; deg[b]++;
  }
  rep(i,n) if(deg[i]>2) ok=false;
  
  YesNo(ok);
}
```