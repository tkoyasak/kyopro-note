# C - Many Balls

No	: 216  
url	: https://atcoder.jp/contests/abc216/tasks/abc216_c  
tag	: [[Bit]]  #ABC #gray

### idea
- 操作を逆にする，すなわち $n \rightarrow 0$ を考えると方針が立てやすい．
	- $n$ が2で割りきれない場合 : 魔法A ($n=n-1$)
	- $n$ が2で割りきれる場合 : 魔法B ($n=n/2$)

bit列の操作
- 例えば，25${}_{10}$を2進数で表すと11001${}_2$と表せる．
- 上の操作は，以下のように解釈できる．
	- 最下位ビットが1 : 魔法A (最下位ビットを０にする)
	- 最下位ビットが0 : 魔法B (論理右シフト)
- 操作を行うと $n$ は以下のように遷移する．
	- $11001_2(25_{10}) \rightarrow 11000_2(24_{10}) \rightarrow 1100_2(12_{10}) \rightarrow 110_2(6_{10}) \rightarrow 11_2(3_{10}) \rightarrow 10_2(2_{10}) \rightarrow 1_2(1_{10}) \rightarrow 0$ 

操作の総数は120回以下となるのか
- 上の操作から各桁最大２回で操作することができる．
- $10^{18} \lt 2^{60}$ なので最悪手120回未満とすることができる．

### code
```cpp
int	main(void)
{
  ll n; cin>>n;
  string ans;

  while(n) {
    if(n&1) {
      ans='A'+ans;
      n--;
    }
    else {
      ans='B'+ans;
      n/=2;
    }
  }

  cout<<ans<<endl;
}
```