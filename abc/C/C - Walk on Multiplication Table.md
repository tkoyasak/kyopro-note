# C - Walk on Multiplication Table

No	: 144  
url	: https://atcoder.jp/contests/abc144/tasks/abc144_c  
tag	: [[全探索]]  #ABC #gray

### idea
- 問題は「$a \times b=N$ となるような $(a,b)$ について $a+b-2$ の最小値を求めよ」となる．
- 対称性から $a \leq b$ としてよいので，$a \leq \sqrt{N}$ までを全探索すればよい．
- $10^{12}$ という特殊制約は，$O(sqrt(N))$ で解いてほしいというメッセージ．

### code
```cpp
int	main(void)
{
  ll n; cin>>n;
  ll ans=INF;
  ll m=sqrt(n)+1;

  reps(i,1,m) {
    if(n%i==0) chmin(ans,i+n/i-2);
  }

  cout<<ans<<endl;
}
```