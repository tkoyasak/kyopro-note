# D - Cooking

No	: 204  
url	: https://atcoder.jp/contests/abc204/tasks/abc204_d  
tag	: [[動的計画法]] [[部分和]]  #ABC #green

### idea
- $\text{dp}[i] \coloneqq$ 料理時間 $T$ について部分和 $i$ を作れるかどうか，と定義する．
- 部分和を求めるときには，`std::bitset` を使うと実装や実行時間を抑えられる．
- 計算量は $\mathcal{O}(N+\sum_{i} T_i)$．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  bitset<100100> dp; dp[0]=1;
  int ans=inf,sum=0;

  rep(i,n) {
    int t; cin>>t;
    sum+=t;
    dp|=dp<<t;
  }
  rep(i,sum+1) if(dp[i]) chmin(ans,max(i,sum-i));

  cout<<ans<<endl;
}
```