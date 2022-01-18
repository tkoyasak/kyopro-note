# D - 射撃王

No	: 023  
url	: https://atcoder.jp/contests/abc023/tasks/abc023_d  
tag	: [[二分探索]]  #ABC #blue #解説AC 

### idea
- すべての風船を高度 $X$ 以内に割ることができるか，という判定問題と見なすことで解ける．
- このとき判定条件は次の通り．
	- 風船 $i$ は $\frac{X-H_i}{S_i}$ 秒以内に割らなければならない．
	- もし $X<H_i$ ならばこの $X$ では不可能となる．
- $X$ の候補は二分探索することで $O(\log(max_{i \in N}(H_i+NS_i)))$ で絞ることができる．
- 計算量は $O(N \log N \times \log(max_{i \in N}(H_i+NS_i)))$

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vi h(n),s(n); rep(i,n) cin>>h[i]>>s[i];

  ll l=0,r=INF;
  while(l+1<r) {
    ll m=(l+r)/2;
    bool ok=true;

    // 各風船を割るまでの制限時間
    vl t(n);
    rep(i,n) {
      if(m<h[i]) ok=false;
      else t[i]=(m-h[i])/s[i];
    }

    // 時間制限が迫っている順にソート
    sort(all(t));
    rep(i,n) if(t[i]<i) ok=false;

    if(ok) r=m;
    else l=m;
  }

  cout<<r<<endl;
}
```