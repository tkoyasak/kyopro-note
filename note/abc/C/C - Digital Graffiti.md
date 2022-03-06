# C - Digital Graffiti

No	: 191  
url	: https://atcoder.jp/contests/abc191/tasks/abc191_c  
tag	: [[図形問題]]  #ABC #green

### idea
- 「ある点 $(x,y)$ が頂点であること」と、「その点の周囲４マス $(S_{x,y},S_{x+1,y},S_{x,y+1},S_{x+1,y+1})$ のうち `#` がちょうど１個または３個あること」が同値となる．
- 自己交叉がないという制約により，対角線上のみに `#` が配置されることはない．

### code
```cpp
int	main(void)
{
  int h,w; cin>>h>>w;
  vs s(h); rep(i,h) cin>>s[i];
  int ans=0;

  rep(i,h-1) rep(j,w-1) {
    int cnt=0;
    rep(di,2) rep(dj,2) if(s[i+di][j+dj]=='#') cnt++;
    if(cnt==1||cnt==3) ans++;
  }
  cout<<ans<<endl;
}
```