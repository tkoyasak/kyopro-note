# C - chokudai

No	: 211  
url	: https://atcoder.jp/contests/abc211/tasks/abc211_c  
tag	: [[動的計画法]]  #ABC #brown

### idea
- 配るDPとして考える．
- `dp[i][i]` を「$S$ の $i$ 文字目までを使って $chokudai$ の $j$ 文字までの部分文字列をつくる方法の総数」と定義する．
- 計算量は $O(N)$ となる．

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
    if(j<9&&s[i]==chokudai[j])
      (dp[i+1][j+1]+=dp[i][j])%=mod;
  }

  cout<<dp[n][8]<<endl;
}
```