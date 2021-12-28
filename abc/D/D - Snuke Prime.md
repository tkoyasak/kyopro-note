# D - Snuke Prime

No	: 188  
url	: https://atcoder.jp/contests/abc188/tasks/abc188_d  
tag	: [[いもす法]]  #ABC #green

### idea

### code
```cpp
int	main(void)
{
  int n,c; cin>>n>>c;
  vpii imos;
  rep(i,n) {
    int a,b,c; cin>>a>>b>>c;
    imos.emplace_back(a,c);
    imos.emplace_back(b+1,-c);
  }
  ll ans=0,p=0;

  sort(all(imos));
  rep(i,imos.size()-1) {
    p+=imos[i].second;
    ll u=imos[i+1].first-imos[i].first;
    ans+=min<ll>(c,p)*u;
  }

  cout<<ans<<endl;
}
```