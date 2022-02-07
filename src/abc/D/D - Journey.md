# D - Journey

No	: 194  
url	: https://atcoder.jp/contests/abc194/tasks/abc194_d  
tag	: [[期待値]]  #ABC #green

### idea
- 有効なカードを引く確率が $p(p \neq 0)$ のとき，有効なカードが来るまでカードを引き続ける回数の期待値は $\dfrac{1}{p}$ となる．
- [解説動画 @snuke](https://www.youtube.com/watch?v=avazOGG7OfY&t=3265s)
- すべて同じ遷移条件のため「どこにいるか」「どこと連結するか」は抽象化していい条件となる．
- 状態の遷移は以下のようになる．
	- 連結数１ -> 連結数２ -> 連結数３ -> ... -> 連結数$N$
- 連結数 $i(1\le i\le n)$ について，$i \rightarrow i+1$ の遷移を考えると次のようになる．
	- $\frac{N-i}{N}$ の確率で次の状態 (連結数 $i+1$) に移る．
	- $\frac{i}{N}$ の確率で同じ状態 (連結数 $i$) に留まる． 
- したがって，期待値に関する事実から $\sum_{i=1}^{n-1} \frac{N}{N-i}$ が答えとなる．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  double ans=0;

  reps(i,1,n) ans+=(double)n/(n-i);

  printf("%.10f\n",ans);
}
```