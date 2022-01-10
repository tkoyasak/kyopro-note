# D - Destroyer Takahashi

No	: 230  
url	: https://atcoder.jp/contests/abc230/tasks/abc230_d  
tag	: [[貪欲法]] [[区間スケジューリング]]  #ABC #green

### idea
- 次のアルゴリズムによってパンチを放つ位置を決めるのが最適となる．
	- 壁が存在する区間 $[L,R]$ のペアを $R$ に対して昇順にソートする．
	- ソートした順に壁を見ていき，壁が破壊されていなければ右端にパンチを放つ．
- [アルゴリズムの正当性の証明 @Nyaan](https://atcoder.jp/contests/abc230/editorial/3013)
- 計算量はソートがボトルネックとなり，$O(N \log N)$．

### code
```cpp
int	main(void)
{
  int n,d; cin>>n>>d;
  vpii p(n);
  rep(i,n) cin>>p[i].second>>p[i].first;
  int ans=0,x=-inf;

  sort(all(p(n)));
  for(auto& [r,l]:p(n)) {
    if(x+d-1<l) ans++,x=r;
  }

  cout<<ans<<endl;
}
```