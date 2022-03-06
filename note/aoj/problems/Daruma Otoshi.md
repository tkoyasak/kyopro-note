# Daruma Otoshi

No	: 1611
url	: https://onlinejudge.u-aizu.ac.jp/problems/1611  
tag	: [[動的計画法]] [[区間DP]]  #AOJ #black 

### idea
- 区間DPはfor文で配列の更新処理を行うと煩雑になりがちなので，メモ化再帰を行うと実装しやすい．

### code
```cpp
int n;
vi w;
vvi dp;
int f(int l,int r) {
  if(~dp[l][r]) return dp[l][r];
  if(r-l<=1) return 0;
  if(r-l==2) return (abs(w[l]-w[l+1])<=1)*2;

  if(abs(w[l]-w[r-1])<=1 && f(l+1,r-1)==r-l-2)
    chmax(dp[l][r],r-l);
  reps(i,l+1,r)
    chmax(dp[l][r],f(l,i)+f(i,r));
  return dp[l][r];
}

int	main(void)
{
  while(true) {
    cin>>n; if(n==0) exit(0);
    w.resize(n); rep(i,n) cin>>w[i];
    dp.assign(n+2,vi(n+2,-1));
  
    cout<<f(0,n)<<endl;
  }
}
```