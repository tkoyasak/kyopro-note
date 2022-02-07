# D - Leaping Tak

No	: 179  
url	: https://atcoder.jp/contests/abc179/tasks/abc179_d  
tag	: [[動的計画法]] [[累積和]]  #ABC #cyan #解説AC 

### idea
- $\text{dp}[i] \coloneqq$ マス $i$ に到達するまでの操作列の個数，と定義する．
- 愚直に計算すると，次のように計算できる．
	$$\text{dp}[i]= \sum_{v \in S} \text{dp}[i-v]$$
- しかし DP の状態量 $\mathcal{O}(N)$ あり，各々について最悪 $\mathcal{O}(N)$ 通りの遷移があるので, $\mathcal{O}(N^2)$ となる．
- 累積和を用いて高速化を行う．
- 集合 $S$ が $K$ 個の区間からなることに着目すると，$\sum_{v \in S} \text{dp}[i-v]$ は $K$ 個の区間についての「区間内の総和」を足し上げたものとなる．
- 配列 $\text{dp}$ の累積和を $\text{w}$ とすると，次のように更新できる．
	$$\text{dp}[i]=\sum_{k=1}^K (\text{w}[i-l_k]-\text{w}[i-r_k-1])$$
- 計算量は $\mathcal{O}(NK)$．

### code
```cpp
int	main(void)
{
  int n,k; cin>>n>>k;
  vi l(k),r(k); rep(i,k) cin>>l[i]>>r[i];
  vector<mint> dp(n+1),w(n+1);

  dp[1]=1; w[1]=1;
  reps(i,2,n+1) {
    rep(j,k) {
      int li=max(0,i-r[j]-1);
      int ri=max(0,i-l[j]);
      dp[i]+=w[ri]-w[li];
    }
    w[i]=w[i-1]+dp[i];
  }

  cout<<dp[n]<<endl;
}
```