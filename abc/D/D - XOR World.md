# XOR World

No	: 121  
url	: https://atcoder.jp/contests/abc121/tasks/abc121_d  
tag	: [[bit]] [[整数]]  #ABC #green

### idea
- [Editorial](https://img.atcoder.jp/abc121/editorial.pdf)
- XOR和について重要な性質がある．任意の偶数について次のことがいえる．
	$$n \oplus (n+1)=1$$
- [解説記事 @drken](https://drken1215.hatenablog.com/entry/2019/03/09/224100)
- XOR和は桁ごとに考えていくのが定石だが，今回は実験してみると解答が見えてくる．
	$$\begin{array}{c|c}
	x              & 0 & 1 & 10 & 11 & 100 & 101 & 110 & 111 & 1000 \\ 
	\hline
	\text{xor sum} & 0 & 1 & 11 & 0 & 100 & 1 & 111 & 0 & 1000
	\end{array}$$
- $x$ が奇数のときは $0$ と $1$ を繰り返している (全体として 4 個足すごとに $0$ になる) ので， これを利用すると次のことがいえる．
	- $x$ が奇数のときは，$\dfrac{x+1}{2}$ が偶数なら $0$，奇数なら $1$
	- $x$ が偶数のときは，$x+1$ が奇数なのでその答えから $x+1$ を引く (XOR の意味で足す)

### code
```cpp
ll f(ll a) {
  auto g=[](ll x) {
    return (x+1)/2%2;
  };
  if(a%2==1) return g(a);
  else return g(a+1)^(a+1); 
}

int	main(void)
{
  ll a,b; cin>>a>>b;

  cout<<f(a-1)^f(b)<<endl;
}
```