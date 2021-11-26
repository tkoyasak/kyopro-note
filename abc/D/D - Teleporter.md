# D - Teleporter

No	: 167  
url	: https://atcoder.jp/contests/abc167/tasks/abc167_d  
tag	: [[ダブリング]]  #ABC #brown

### idea
- $\text{dl}[i][cur]$ := 現在頂点 $cur$ にいて，そこから $2^i$ 回遷移したときの遷移先，と定義する．
- $2^i=2^{i-1}+2^{i-1}$ なので，$2^i$回遷移した先は以下で求めることができる．
    $$\text{dl}[i][cur]=\text{dl}[i-1][\text{dl}[i-1][cur]]$$
- 計算量は $O(N \log K)$

### code
```cpp
int	main(void)
{
  const int D=60;

  ll n,k; cin>>n>>k;
  vi a(n); rep(i,n) cin>>a[i];
  int dl[D][n],cur=0;

  rep(i,n) dl[0][i]=a[i]-1;
  reps(i,1,D) rep(j,n) dl[i][j]=dl[i-1][dl[i-1][j]];

  rrep(i,D-1,0) if(k&(1LL<<i)) cur=dl[i][cur];
  cout<<cur+1<<endl;
}
```