# C - Strange Bank

No	: 099  
url	: https://atcoder.jp/contests/abc099/tasks/abc099_c  
tag	: [[動的計画法]] [[貪欲法]] #ABC #green

### idea
- さまざまな方法で解けるとのこと．
- 計算量はすべて $O(N \log N)$．
- [解説記事 @drken](https://qiita.com/drken/items/ace3142967c4f01d42e9)
1. メモ化再帰 (動的計画法)
2. 配るDP (動的計画法)
3. 全探索 + 貪欲法 [@Kutimoti](https://kutimoti.hatenablog.com/entry/2018/06/10/232718)

### code
```cpp
int memo[101010];
int	f(int n)
{
  if(n==0) return 0;
  if(memo[n]) return memo[n];

  int res=n;
  for(int p=1;p<=n;p*=6) chmin(res,f(n-p)+1);
  for(int p=1;p<=n;p*=9) chmin(res,f(n-p)+1);

  return memo[n]=res;
}

int	main(void)
{
  int n; cin>>n;

  cout<<f(n)<<endl;
}
```

```cpp
int	main(void)
{
  int n; cin>>n;
  vi dp(101010,n);

  dp[0]=0;
  rep(i,n) {
    for(int p=1;i+p<=n;p*=6) chmin(dp[i+p],dp[i]+1);
    for(int p=1;i+p<=n;p*=9) chmin(dp[i+p],dp[i]+1);
  }

  cout<<dp[n]<<endl;
}
```

```cpp
int	main(void)
{
  int n; cin>>n;
  int ans=n;

  auto f=[&](int n, int x) {
    int res=0;
    while(n>0) {
      res+=n%x;
      n/=x;
    }
    return res;
  };

  rep(i,n+1) {
    int d=f(i,6)+f(n-i,9);
    chmin(ans,d);
  }

  cout<<ans<<endl;
}
```