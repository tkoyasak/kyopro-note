# D - Lamp

No	: 129  
url	: https://atcoder.jp/contests/abc129/tasks/abc129_d  
tag	: [[Grid]]  #ABC #green

### idea
- 障害物のないマスの連続する区間内であれば，どこに位置していてもライトによって照らすことのできるマスの数は等しい．
- これを行方向 / 列方向で前処理をしておくと，各マスについて $O(1)$ で求めることができる．

### code
```cpp
int	main(void)
{
  int h,w; cin>>h>>w;
  vs s(h); rep(i,h) cin>>s[i];
  vector<vi> cnt(h,vi(w));
  int ans=0;

  rep(i,h) {
    vb done(w,false);
    rep(j,w) if(!done[j] && s[i][j]=='.') {
      int r=0;
      while(j+r<w && s[i][j+r]=='.') ++r;
      rep(k,r) {
        cnt[i][j+k]+=r;
        done[j+k]=true;
      }
    }
  }
  rep(j,w) {
    vb done(h,false);
    rep(i,h) if(!done[j] && s[i][j]=='.') {
      int r=0;
      while(i+r<h && s[i+r][j]=='.') ++r;
      rep(k,r) {
        cnt[i+k][j]+=r;
        done[i+k]=true;
      }
    }
  }
  rep(i,h) rep(j,w) chmax(ans,cnt[i][j]-1);

  cout<<ans<<endl;
}
```

```cpp
int	main(void)
{
  int h,w; cin>>h>>w;
  vs s(h); rep(i,h) cin>>s[i];
  vector<vi> c(h,vi(w)),d(w,vi(h));
  int ans=0;

  rep(i,h) {
    int k=0; c[i][0]=k;
    reps(j,1,w) {
      if(s[i][j]!=s[i][j-1]) ++k;
      c[i][j]=k; 
    }
  }
  rep(j,w) {
    int k=0; d[j][0]=k;
    reps(i,1,h) {
      if(s[i][j]!=s[i-1][j]) ++k;
      d[j][i]=k; 
    }
  }

  rep(i,h) rep(j,w) if(s[i][j]=='.') {
    int cnt=-1;
    int u=c[i][j],v=d[j][i];
    cnt+=upper_bound(all(c[i]),u)-lower_bound(all(c[i]),u);
    cnt+=upper_bound(all(d[j]),v)-lower_bound(all(d[j]),v);
    chmax(ans,cnt);
  }

  cout<<ans<<endl;
}
```