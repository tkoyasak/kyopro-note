# E - Sum Equals Xor

No	: 129  
url	: https://atcoder.jp/contests/abc129/tasks/abc129_e  
com	: https://youtu.be/L8grWxBlIZ4?t=5353  
tag	: [[動的計画法]] [[桁DP]]  #ABC #cyan #解説AC 

### idea
- $a+b=a \oplus b$ を読みかえると $a \land b=0$ なので，問題は次のようになる．
> $a+b \le L$ かつ $a \land b=0$ を満たす $(a,b)$ の組はいくつか．
- 各桁について $a+b=0$ または $a+b=1$ となるような $(a,b)$ の組を数える．
- $a+b=1$ の場合は，各遷移について $(a,b)=(1,0),(0,1)$ の２通りあるので $\times 2$ するのに注意．

### code
```cpp
int	main(void)
{
  string s; cin>>s;
  int n=sz(s);

  // dp[digit][smaller]
  vector<vector<mint>> dp(n+1,vector<mint>(2));
  dp[0][0]=1;

  rep(i,n) {
    // a+b = 0
    if(s[i]=='0') {
      dp[i+1][0]+=dp[i][0];
      dp[i+1][1]+=dp[i][1];
    }
    else {
      dp[i+1][1]+=dp[i][0]+dp[i][1];
    }

    // a+b = 1
    if(s[i]=='0')
      dp[i+1][1]+=dp[i][1]*2;
    else {
      dp[i+1][0]+=dp[i][0]*2;
      dp[i+1][1]+=dp[i][1]*2;
    }
  }

  cout<<dp[n][0]+dp[n][1]<<endl;
}
```