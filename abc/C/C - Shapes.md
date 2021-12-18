# C - Shapes

No	: 218  
url	: https://atcoder.jp/contests/abc218/tasks/abc218_c  
tag	: [[図形問題]]  #ABC #green

### idea
- `#` の位置を集合として持つと，移動や回転で範囲外アクセスを気にする必要がなくなる．
- `set` で持つと，一番左上の座標は集合の先頭に並ぶ．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vs s(n); rep(i,n) cin>>s[i];
  vs t(n); rep(i,n) cin>>t[i];
  set<pair<int,int>> u,v;
  rep(i,n) rep(j,n) if(s[i][j]=='#') u.emplace(j,i);
  rep(i,n) rep(j,n) if(t[i][j]=='#') v.emplace(j,i);

  auto move=[](set<pair<int,int>> &p) {
    set<pair<int,int>> q;
    int mx=p.begin()->first,my=p.begin()->second;
    fore(i,p) q.emplace(i.first-mx,i.second-my);
    swap(p,q);
  };
  auto rotate=[](set<pair<int,int>> &p) {
    set<pair<int,int>> q;
    fore(i,p) q.emplace(i.second,-i.first);
    swap(p,q);
  };

  bool ok=false;
  move(u);
  rep(i,4) {
    move(v);
    if(u==v) ok=true;
    rotate(v);
  }
  YesNo(ok);
}
```