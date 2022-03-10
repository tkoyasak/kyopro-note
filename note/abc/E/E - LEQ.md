# E - LEQ

No	: 221  
url	: https://atcoder.jp/contests/abc221/tasks/abc221_e  
com	: https://youtu.be/uK1LOoaN5lA?t=3370  
tag	: [[フェニック木]] [[セグメント木]] #ABC #cyan #解説AC   

### idea
- $A$ の要素が互いに異なると仮定すると，任意の $l,r$ $(1 \le l \lt r \le N)$ について次が成り立つ．
	- $A'_1=A_l$ かつ $A'_k=A_r$ が成り立つような $A$ の部分列 $A'=(A'_1,A'_2,\dots,A'_k)$ は，$2^{r-l-1}$ 個存在する．
- $A$ の要素が互いに異なると仮定した場合の答えは次となる．
	- $1 \le l \lt r \le N$ かつ $A_l \le A_r$ を満たすすべての組 $(l,r)$ に対する $2^{r-l-1}$ の総和．
- $2^{r-l-1}=\dfrac{2^{r-1}}{2^l}$ より，$B_r=$ ($1\le l \lt r$ かつ $A_l\le A_r$ を満たすようなすべての $l$ に対する $\frac{1}{2^l}$ の総和) と定義すると，
	- 答えは $\sum_{r=1}^{N}  2^{r-1} \times B_r$．
- $B$ は $A$ の要素を座標圧縮した上で，Fenwick Treeを用いて添字の昇順に走査することで求められる．
- 計算量は $\mathcal{O} (N \log N)$．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];

  // 座標圧縮
  map<int,int> mp; fore(i,a) mp[i]=0;
  int m=0; fore(i,mp) i.sd=m++;

  // 昇順に走査
  fenwick_tree<mint> ft(m);
  mint ans=0,t=1,rt=1;
  rep(i,n) {
    int x=mp[a[i]];
    ans+=t*ft.sum(0,x+1);
    t*=2,rt/=2;
    ft.add(x,rt);
  }

  cout<<ans.val()<<endl;
}
```