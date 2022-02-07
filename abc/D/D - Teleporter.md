# D - Teleporter

No	: 167  
url	: https://atcoder.jp/contests/abc167/tasks/abc167_d  
tag	: [[ダブリング]]  #ABC #brown

### idea
- $\text{dp}[i][cur] \coloneqq$ 現在頂点 $cur$ にいて，そこから $2^i$ 回遷移したときの遷移先，と定義する．
- $2^i=2^{i-1}+2^{i-1}$ なので，$2^i$回遷移した先は以下で求めることができる．
    $$\text{dp}[i][cur]=\text{dp}[i-1][\text{dp}[i-1][cur]]$$
- 計算量は $\mathcal{O}(N \log K)$．

### code
```cpp
int	main(void)
{
  const int D=60;

  ll n,k; cin>>n>>k;
  vi a(n); rep(i,n) cin>>a[i];
  int dp[D][n];
  int cur=0;

  rep(i,n) dp[0][i]=a[i]-1;
  rep(i,1,D) rep(j,n) dp[i][j]=dp[i-1][dp[i-1][j]];

  per(i,D) if(k&bit(i)) cur=dp[i][cur];
  cout<<cur+1<<endl;
}
```