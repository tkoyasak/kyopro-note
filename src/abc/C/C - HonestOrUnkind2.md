# C - HonestOrUnkind2

No	: 147  
url	: https://atcoder.jp/contests/abc147/tasks/abc147_c  
tag	: [[全探索]]  #ABC #green

### idea

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  graph honest(n),unkind(n);
  rep(i,n) {
    int a; cin>>a;
    rep(j,a) {
      int b,s; cin>>b>>s;
      if(s) honest[i].push_back(b-1);
      else unkind[i].push_back(b-1);
    }
  }
  int ans=0;

  rep(mask,1<<n) {
    bool ok=true;
    rep(i,n) if(mask>>i&1) {
      fore(h,honest[i]) if(!(mask>>h&1)) ok=false;
      fore(u,unkind[i]) if(mask>>u&1) ok=false;
    }
    if(ok) chmax(ans,__builtin_popcount(mask));
  }

  cout<<ans<<endl;
}
```