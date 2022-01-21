# Matrix Chain Multiplication

No	: ALDS1 - 10B  
url	: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_B  
tag	: [[動的計画法]] [[区間DP]]  #AOJ  #black 

### idea
- 行列 $l \times m$ と行列 $m \times n$ の積の計算に必要な演算回数は $l \times m \times n$ となる．
- この問題では，行列 $M_1,M_2,\dots,M_n$ の積 (連鎖行列積) を計算するのに必要な演算回数の最小値を求める．
- すべての可能な順番を調べると $O(N!)$ かかるが，より小さな部分問題に分割できるので動的計画法が適用できる．
- $\text{dp}[l][r] \coloneqq$ 連鎖行列積 $M_l \times M_{l+1}\times \dots \times M_r$ を計算するのに必要な演算回数の最小値，と定義する．
- $\text{dp}[l][r]$ について，分割位置 $m$ をすべて調べてその最小値が最適解となる．
- [連鎖行列積問題 @がぶ飲みミルク珈琲](https://ttrsq.exblog.jp/24318687/)

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vi row(n),col(n); rep(i,n) cin>>row[i]>>col[i];

  vvi dp(n,vi(n,inf));
  rep(i,n) dp[i][i]=0;

  // d := l,r の差分
  reps(d,1,n) rep(l,n-d) {
    int r=l+d;
    reps(m,l,r) {
      // cost(左側行列積) + cost(右側行列積) + cost(行列計算)
      chmin(dp[l][r],dp[l][m]+dp[m+1][r]+row[l]*col[m]*col[r]);
    }
  }

  cout<<dp[0][n-1]<<endl;
}
```