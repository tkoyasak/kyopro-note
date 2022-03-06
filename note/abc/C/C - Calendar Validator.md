# C - Calendar Validator

No	: 225  
url	: https://atcoder.jp/contests/abc225/tasks/abc225_c  
tag	: [[全探索]]  #ABC #gray 

### idea
- $A$ のある要素が与えられたとき，それが何行目何列目なのかは一意に定まる．
- $B$ の各要素が $A$ の何行目何列目なのかを求め，それらが矩形領域を成しているかを判定すればよい．
- $B_{i,0}$ の列位置 $+$ $M\gt7$ となる場合に注意．

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  vvi b(n,vi(m)); rep(i,n) rep(j,m) cin>>b[i][j],b[i][j]--;

  int si=b[0][0]/7,sj=b[0][0]%7;
  if(sj+m>7) {
    cout<<"No"<<endl;
    return 0;
  }
  rep(i,n) rep(j,m) {
    int nb=(si+i)*7+(sj+j);
    if(b[i][j]!=nb) {
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}
```