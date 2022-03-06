# C - Duodecim Ferra

No	: 185  
url	: https://atcoder.jp/contests/abc185/tasks/abc185_c  
tag	: [[組み合わせ]]  #ABC #gray

### idea
- $L(\ge 12)$ 個の $\bigcirc$ の間に11個の $|$ を入れる組み合わせ問題となる．
- 答えは ${}_{L-1}\mathrm{ C }_{11}=\frac{(L-1)(L-2)\cdots(L-11)}{11!}$ に等しい．
- 分子は 64bit 整数型に収まらないことがあるので要注意．

オーバーフローの回避
- パスカルの三角形を用いた計算を行う．
- 順次割りながら計算する．(以下コードではこの方法を用いた．)
- 128bit 整数型を使う．


### code
```cpp
int	main(void)
{
  int l; cin>>l;
  ll ans=1;

  reps(i,1,12) {
    ans*=l-i;
    ans/=i;
  }

  cout<<ans<<endl;
}
```