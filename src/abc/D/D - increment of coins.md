# D - increment of coins

No	: 184  
url	: https://atcoder.jp/contests/abc184/tasks/abc184_d  
tag	: [[期待値]] [[動的計画法]]  #ABC #cyan #解説AC 

### idea
- 確率DPと呼ばれるジャンルの問題．
- $\text{dp}[i][j][k] \coloneqq$ 金貨 $i$ 枚，銀貨 $j$ 枚，銅貨 $k$ 枚ある状態での期待値，と定義する．
	$$\text{dp}[i][j][k] = \text{dp}[i+1][j][k] \times \frac{i}{i+j+k} + \text{dp}[i][j+1][k] \times \frac{j}{i+j+k} + \text{dp}[i][j][k+1] \times \frac{k}{i+j+k} + 1$$
- ゴールの状態 (期待値 $0$) からスタートし，金貨 $A$ 枚，銀貨 $B$ 枚，銅貨 $C$ 枚の状態に達するまでに何回遷移できますか？，というお気持ち．

### code
```cpp 
const int X=100;
double dp[X+1][X+1][X+1];
int	main(void)
{
  int a,b,c; cin>>a>>b>>c;
  
  rrep(i,X-1,0) rrep(j,X-1,0) rrep(k,X-1,0) {
    if(i+j+k==0) continue;
    double cur=0;
    cur+=dp[i+1][j][k]*i;
    cur+=dp[i][j+1][k]*j;
    cur+=dp[i][j][k+1]*k;
    dp[i][j][k]=cur/(i+j+k)+1;
  }

  cout<<<<dp[a][b][c]<<endl;
}
```