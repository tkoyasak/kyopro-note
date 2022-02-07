# E - Akari

No	: 182  
url	: https://atcoder.jp/contests/abc182/tasks/abc182_e  
tag	: [[Grid]]  #ABC #green

### idea

### code
```cpp
int	main(void)
{
  int h,w,n,m; cin>>h>>w>>n>>m;
  vs g(h,string(w,'.'));
  rep(i,n) {
    int a,b; cin>>a>>b;
    g[a-1][b-1]='l';
  }
  rep(i,m) {
    int a,b; cin>>a>>b;
    g[a-1][b-1]='b';
  }
  vvi cnt(h,vi(w,0));
  int ans=0;

  rep(i,h) {
    vb done(w,false);
    rep(j,w) if(!done[j] && g[i][j]!='b') {
      int r=0;
      bool light=false;
      while(j+r<w && g[i][j+r]!='b') {
        done[j+r]=true;
        if(g[i][j+r]=='l') light=true;
        ++r;
      }
      if(light) rep(k,r) cnt[i][j+k]++;
    }
  }
  rep(j,w) {
    vb done(h,false);
    rep(i,h) if(!done[i] && g[i][j]!='b') {
      int r=0;
      bool light=false;
      while(i+r<h && g[i+r][j]!='b') {
        done[i+r]=true;
        if(g[i+r][j]=='l') light=true;
        ++r;
      }
      if(light) rep(k,r) cnt[i+k][j]++;
    }
  }
  rep(i,h) rep(j,w) if(cnt[i][j]) ans++;

  cout<<ans<<endl;
}
```