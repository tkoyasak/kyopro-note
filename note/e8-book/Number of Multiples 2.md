# Number of Multiples 2

No	: 5.4.4  
url	: https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_be  
tag	: [[包除原理]] [[数え上げ問題]] [[全探索]]  #E8-book

### idea
- 集合 $S_1, S_2, S_3, \dots, S_N$ の和集合の要素数は以下で表される．
- $N$ 個の集合の中から１つ以上選ぶ方法は $2^N-1$ 通りあるが，それらすべてに対して以下の値を加算したもの．
	- 奇数個選んだとき : 選んだ集合の共通部分の要素数 $\times (+1)$
	- 偶数個選んだとき : 選んだ集合の共通部分の要素数 $\times (-1)$

### code
```cpp
int	main(void)
{
  ll n; int k; cin>>n>>k;
  vi v(k); rep(i,k) cin>>v[i];
  ll ans=0;

  rep(msk,1,bit(k)) {
    ll val=1;
    rep(i,k) if(msk&bit(i)) val=lcm(val,v[i]);
    if(pcnt(msk)&1) ans+=n/val;
    else ans-=n/val;
  }

  cout<<ans<<endl;
}
```