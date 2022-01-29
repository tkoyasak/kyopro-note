# E - Rook Path

No	: 232  
url	: https://atcoder.jp/contests/abc232/tasks/abc232_e  
com	: https://youtu.be/kORAFq34YTI?t=3382  
tag	: [[動的計画法]] [[Grid]]  #ABC #cyan #解説AC 

### idea
- $\text{dp}[i][j] \coloneqq$ ルークが $(i,j)$ に置かれている方法の総数，と定義する．
- 行についての遷移を考えると次の４通りになる．
	- $i=x_2 \Rightarrow i=x_2$ への遷移 : $0$ 通り
	- $i=x_2 \Rightarrow i \neq x_2$ への遷移 : $H-1$ 通り
	- $i \neq x_2 \Rightarrow i=x_2$ への遷移 : $1$ 通り
	- $i \neq x_2 \Rightarrow i\neq x_2$ への遷移 : $H-2$ 通り
- 列の遷移についても同様に考えることができる．
- 計算量は $\mathcal{O}(K)$．

### code
```cpp
int	main(void)
{
  int h,w,k; cin>>h>>w>>k;
  int si,sj,ti,tj; cin>>si>>sj>>ti>>tj;
  vvm dp(2,vm(2));

  dp[si==ti][sj==tj]=1;
  rep(k) {
    vvm t(2,vm(2));
    swap(t,dp);

    rep(i,2) {
      dp[i][0]+=t[i][0]*(w-2);
      dp[i][0]+=t[i][1]*(w-1);
      dp[i][1]+=t[i][0];
    }
    rep(j,2) {
      dp[0][j]+=t[0][j]*(h-2);
      dp[0][j]+=t[1][j]*(h-1);
      dp[1][j]+=t[0][j];
    }
  }

  cout<<dp[1][1]<<endl;
}
```