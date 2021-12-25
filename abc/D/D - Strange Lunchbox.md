# D - Strange Lunchbox

No	: 219  
url	: https://atcoder.jp/contests/abc219/tasks/abc219_d  
tag	: [[動的計画法]] [[ナップサック問題]]  #ABC #green

### idea
- ナップサック問題．
- 下記をすべて満たす状態を状態 $(i,j,k)$ とする．
	- $i$ 番目の弁当までを買うかどうか決定している．
	- それまでに手に入れたたこ焼きは $j$ 個，たい焼きは $k$ 個．
- 買い物を始める前の初期状態は状態 $(0,0,0)$．
- $\text{dp}[i][j][k] \coloneqq$ 状態 $(i,j,k)$ に達するまでに購入する弁当の個数の最小値，と定義する．
- ただし，$(j,k)$ が $(X,Y)$ を超過する分は考慮しなくていい．
- 計算量は $O(NXY)$．

### code
```cpp
int	main(void)
{
  int n,x,y; cin>>n>>x>>y;
  vvi dp(x+1,vi(y+1,inf));

  dp[0][0]=0;
  rep(i,n) {
    int a,b; cin>>a>>b;
    rrep(j,x,0) rrep(k,y,0) {
      int nx=min(x,j+a),ny=min(y,k+b);
      chmin(dp[nx][ny],dp[j][k]+1);
    }
  }
  
  cout<<(dp[x][y]==inf?-1:dp[x][y])<<endl;
}
```