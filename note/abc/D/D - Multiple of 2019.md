# D - Multiple of 2019

No	: 164  
url	: https://atcoder.jp/contests/abc164/tasks/abc164_d  
tag	: [[動的計画法]] [[剰余]]  #ABC #cyan #解説AC 

### idea
- $S=31415926535$ の場合を考える．このとき $S_{4,8}=15926$ が $2019$ の倍数であるかを判定したい．
- この部分文字列を次のように考える．
  $$15926= \frac{15926535-535}{10^3}$$
- このとき $10$ は $2019$ と互いに素なので，$15926$ が $2019$ であるかどうかは上式右辺の分子のみに着目すればいい．
- 分子が $2019$ の倍数かどうかは，分子を $A-B$ と表したときに $A \equiv B \pmod{2019}$ となればいい．


### code
```cpp
int	main(void)
{
  const int M=2019;
  string s; cin>>s;
  int n=sz(s),p=1,sum=0;
  vi cnt(M);
  ll ans=0;

  reverse(all(s));
  rep(i,n) {
    cnt[sum]++;
    sum=(sum+(s[i]-'0')*p)%M;
    ans+=cnt[sum];
    p=p*10%M;
  }

  cout<<ans<<endl;
}
```