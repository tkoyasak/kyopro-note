# D - Wall

No	: 079  
url	: https://atcoder.jp/contests/abc079/tasks/abc079_d  
tag	: [[最短経路問題]] [[フロイド･ワーシャル法]]  #ABC #green

### idea

### code
```cpp
int	main(void)
{
  int h,w; cin>>h>>w;
  int c[10][10]; rep(i,h) rep(j,w) cin>>c[i][j];
  int a[h][w]; rep(i,h) rep(j,w) cin>>a[i][j];
  int ans=0;

  rep(k,10) rep(i,10) rep(j,10) chmin(c[i][j],c[i][k]+c[k][j]);
  rep(i,h) rep(j,w) if(a[i][j]>=0) ans+=c[a[i][j]][1];

  cout<<ans<<endl;
} 
```