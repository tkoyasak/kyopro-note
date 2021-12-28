# D - Make Them Even

No	: 109  
url	: https://atcoder.jp/contests/abc109/tasks/abc109_d  
tag	: [[構築]]  #ABC #green

### idea
- グリッド上に置かれた全コインの枚数の偶奇は変えられないので，操作終了後に奇数個となるマスの個数は，次のようになるのが最適解と言える．
	- 全コインの枚数が奇数ならば，１
	- 全コインの枚数が偶数ならば，０
- 実装は次の２段階で行う．
	1. すべての列について $1$ 行目から見ていき，奇数のマスがあれば，下のマスに押し付ける．
		この操作を $h-1$ 行目まで行うと，$1 \sim h-1$ 行はすべて偶数のマスとなる．
	2. $h$ 行目について $1$ 列目から見ていき，奇数のマスがあれば，右のマスに押し付ける．
		この操作を $w-1$ 列目まで行うと， $h$ 行の $1 \sim w-1$ 列はすべて偶数のマスとなる．
		最後の $h$ 行 $w$ 列 のマスの偶奇は全コインの枚数の偶奇による．


### code
```cpp
int	main(void)
{
  int h,w; cin>>h>>w;
  vvi a(h,vi(w)); rep(i,h) rep(j,w) cin>>a[i][j];
  vector<tuple<int,int,int,int>> ans;

  rep(i,h-1) rep(j,w) if(a[i][j]%2) {
    a[i+1][j]++;
    ans.push_back(make_tuple(i,j,i+1,j));
  }
  rep(j,w-1) if(a[h-1][j]%2) {
    a[h-1][j+1]++;
    ans.push_back(make_tuple(h-1,j,h-1,j+1));
  }

  cout<<ans.size()<<endl;
  fore(t,ans) {
    int i,j,k,l;
    tie(i,j,k,l)=t;
    printf("%d %d %d %d\n",i+1,j+1,k+1,l+1);
  }
}
```