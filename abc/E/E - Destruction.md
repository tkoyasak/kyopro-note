# E - Destruction

No	: 218  
url	: https://atcoder.jp/contests/abc218/tasks/abc218_e  
tag	: [[最小全域木問題]] [[クラスカル法]]  #ABC #green

### idea

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  vector<pair<int,pii>> es;
  rep(i,m){
    int a,b,c; cin>>a>>b>>c; a--; b--;
    es.emplace_back(c,pii(a,b));
  }
  ll ans=0;
  UnionFind uf(n);

  sort(all(es));
  for(auto [cost,e]:es) {
    auto [a,b]=e;
    if(cost<0 || !uf.same(a,b)) uf.unite(a,b);
    else ans+=cost;
  }
  
  cout<<ans<<endl;
}
```