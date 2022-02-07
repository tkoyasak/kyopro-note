# D - Islands War

No	: 103  
url	: https://atcoder.jp/contests/abc103/tasks/abc103_d  
tag	: [[貪欲法]] [[区間スケジューリング]]  #ABC #cyan

### idea
- 区間スケジューリングに帰着させることができる．

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  vpii p(m); rep(i,m) cin>>p[i].sd>>p[i].ft;
  int ans=0,x=0;

  sort(all(p));
  for(auto& [r,l]:p) {
    if(x>l) continue;
    ans++,x=r;
  }
  
  cout<<ans<<endl;
}
```