# D - Digit Sum Replace

No	: DISCO presents ディスカバリーチャンネル コードコンテスト2020 予選  
url	: https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d  
com	: https://youtu.be/BssyLgQvdcY?t=983  
tag	: [[整数問題]]  #ARC #blue #解説AC 

### idea
- いろいろと実験してみると，どんな数値に対してどんな順序で操作を行っても，回数が等しくなる気がしてくる．
- $c \coloneqq$ 桁数，$s \coloneqq$ 各桁の値の総和，と定義する．
- 一回の操作による変化は次の２通りとなる．
	- $(c,s) \Rightarrow (c-1,s)$ : 桁数が１減る e.g. $200482 \Rightarrow 20482$
	- $(c,s) \Rightarrow (c,s-9)$ : 各桁の値の総和が９減る e.g. $20482 \Rightarrow 20122$
- 最終的に $(1,s(\le 9))$ となるまでの操作回数は次のように求められる．
	$$(\sum_{i=1}^{M} {c_i} -1) + (\sum_{i=1}^{M} {d_i c_i} -1) / 9$$

### code
```cpp
int	main(void)
{
  int m; cin>>m;
  ll s=0,t=0;
  rep(i,m) {
    ll d,c; cin>>d>>c;
    s+=c;
    t+=d*c;
  }

  cout<<(s-1)+(t-1)/9<<endl;
}
```