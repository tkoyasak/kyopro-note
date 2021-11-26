# C - chokudai

No	: 211  
url	: https://atcoder.jp/contests/abc211/tasks/abc211_c  
tag	: [[動的計画法]]  #ABC #brown

### idea
- 配るDPとして考える．
- 計算量は $O(N)$ となる．
- $\text{dp}[i][j]$ := $S$ の $i$ 文字目までを使って $chokudai$ の $j$ 文字までの部分文字列をつくる場合の数，と定義できる．
- $i+1$ 文字目までを決めるのに必要なのは，$i$ 文字目の情報であり，高々１箇所の変更しかないため，１次元リストを使い回すこともできる．

### code
```cpp
int	main(void)
{
  string s; cin>>s;
  string chokudai="chokudai";
  int n=s.size();
  vector<vi> dp(n+1,vi(9));

  dp[0][0]=1;
  rep(i,n) rep(j,9) {
    (dp[i+1][j]+=dp[i][j])%=mod;
    if(s[i]==chokudai[j])
      (dp[i+1][j+1]+=dp[i][j])%=mod;
  }

  cout<<dp[n][8]<<endl;
}
```

```cpp
int	main(void)
{
  string s; cin>>s;
  string chokudai="*chokudai";
  int n=s.size();
  vi dp(9);

  dp[0]=1;
  rep(i,n) reps(j,1,9) {
    if(s[i]==chokudai[j])
      (dp[j]+=dp[j-1])%=mod;
  }

  cout<<dp[8]<<endl;
}
```