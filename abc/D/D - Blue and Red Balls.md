# D - Blue and Red Balls

No	: 132  
url	: https://atcoder.jp/contests/abc132/tasks/abc132_d  
tag	: [[組み合わせ]]  #ABC #green

### idea
- 「ちょうど $i$ 回の操作をすると，青いボールを回収できる」
	$\Leftrightarrow$ 「青いボールが連続する区間がちょうど $i$ 個存在する」
- $N=6,i=2$ の場合を考えてみると，[青,赤,青] が最小構成となるので，求める場合の数は次の２つの組み合わせとなる．
	1. 残りの青を２グループある青にどう分配するか
	2.  残りの赤を３グループある赤にどう分配するか
- 次の通り変数を定義する．
	- $\text{blue} \coloneqq$ 青いボールの数
	- $\text{red} \coloneqq$ 赤いボールの数
	- $\text{b}=\text{blue}-i \coloneqq$ 青いボールの残りの数
	- $\text{r}=\text{red}-(i-1) \coloneqq$ 赤いボールの残りの数 
- 求める組み合わせは次の通り．
	1. 残りの青を $i$ グループある青にどう分配するか $\rightarrow {}_{i}\mathrm{H}_b$
	2. 残りの赤を $i+1$ グループある赤にどう分配するか $\rightarrow {}_{i+1}\mathrm{H}_r$

### code
```cpp
int	main(void)
{
  Combination<mint,4040> comb;
  int n,k; cin>>n>>k;
  int blue=k,red=n-k;

  reps(i,1,k+1) {
    int b=blue-i,r=red-(i-1);
    mint ans=comb.nhk(i,b)*comb.nhk(i+1,r);
    cout<<ans<<endl;
  }
}
```