# D - Game in Momotetsu World

No	: 201  
url	: https://atcoder.jp/contests/abc201/tasks/abc201_d  
com	: https://youtu.be/Wx6020jI4NM?t=1587  
tag	: [[動的計画法]] [[ミニマックス法]] [[Grid]]  #ABC #cyan #解説AC 

### idea
- ゲームの勝敗は (高橋くんのスコア) - (青木くんのスコア) で判定できる．
- $\text{dp}[i][j] \coloneqq$ マス $(i,j)$ からスタートしたときの (自分のスコア) - (相手のスコア) の最大値，と定義する．
- このように定義することで，高橋くんと青木くんの場合分けをしなくて済む．
- 右下のマスから順に最適解を求めていくことになる．
- 手番によって利得を最小化，最大化する戦略を**ミニマックス法**という．

### code
```cpp
int h,w;
int a[2005][2005];
bool seen[2005][2005];
int memo[2005][2005];

int dp(int i,int j) {
  if(i==h-1 && j==w-1) return 0;
  if(seen[i][j]) return memo[i][j];

  seen[i][j]=true;
  int res=-inf;
  if(i+1<h) res=max(res,a[i+1][j]-dp(i+1,j));
  if(j+1<w) res=max(res,a[i][j+1]-dp(i,j+1));
  return memo[i][j]=res;
}

int	main(void)
{
  cin>>h>>w;
  rep(i,h) rep(j,w) {
    char c; cin>>c;
    a[i][j]=(c=='+'?1:-1);
  }

  int ans=dp(0,0);
  if(ans==0) cout<<"Draw"<<endl;
  if(ans<0) cout<<"Aoki"<<endl;
  if(ans>0) cout<<"Takahashi"<<endl;
}
```