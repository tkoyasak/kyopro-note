# Log Inequality 2

No	: 5.10.5  
url	: https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_by  
tag	: [[整数問題]]  #E8-book 

### idea
- $\log_2 a \lt b\log_2 c \Leftrightarrow a \lt c^b$ かどうかを判定する．
- $1 \le a \le 10^{18}$ , $1 \le b \le 10^{18}$ , $1 \le c \le 10^{18}$ なので誤差やオーバーフローに対処しなければばらない．
- 累乗計算をしている途中で右辺の値が上回ったらその時点で Yes 確定．
- ただし，$c=1$ のケースでは何乗しても $1$ なので累乗処理を行わない．
- $2^{60} \gt 10^{18}$ なので $c \ge 2$ のケースでは必ず60回以内でループ処理が終わる． 

### code
```cpp
int	main(void)
{
  ll a,b,c; cin>>a>>b>>c;
  
  if(c==1) {
    cout<<"No"<<endl;
    return 0;
  }

  ll v=1;
  rep(b) {
    if(a/c<v) {
      cout<<"Yes"<<endl;
      return 0;
    }
    v*=c;
  }
  cout<<"No"<<endl;
}
```