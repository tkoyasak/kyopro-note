# E - Sequence Decomposing

No	: 134  
url	: https://atcoder.jp/contests/abc134/tasks/abc134_e  
tag	: [[動的計画法]] [[最長増加部分列問題]]  #ABC #cyan #解説AC 

### idea
- 「LISの双対問題」ともいうべき有名問題．
- 配列の要素を順に見ていき，いくつかの山に分ける．各山は単調増加となるようにしたい．
- 例えば $A = (3,5,1,2,8,7,4,6)$ とすると，次のように並べるのが適当となる．
	- $3 \rightarrow 5 \rightarrow 8$
	- $1 \rightarrow 2 \rightarrow 7$
	- $4 \rightarrow 6$
- 要素 $A_i$ のときの並べ方を一般化すると，次の通り．
	- すでにある各山のてっぺんの値のうち，$A_i$ 未満の範囲で最大の値をもつ山に $A_i$ を並べる．
	- そのような山がない場合は新たに $A_i$ のみからなる山をつくる．
- このとき各山のてっぺんの値は単調減少になっているので，どの山に重ねるかは二分探索で求められる．
- あらかじめ $A$ を反転させて「各山を狭義単調減少に並べる」という設定にすれば扱いやすい．
	- $6 \rightarrow 4 \rightarrow 2 \rightarrow 1$
	- $7 \rightarrow 5 \rightarrow 3$
	- $8$
- 以上の過程は LIS を求めるDPそのもの！

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  vi lis;

  reverse(all(a));
  fore(x,a) {
    if(sz(lis)==0) lis.emplace_back(x);
    else {
      if(x>=lis.back()) lis.emplace_back(x);
      else *upper_bound(all(lis),x)=x;
    }
  }

  cout<<sz(lis)<<endl;
}
```