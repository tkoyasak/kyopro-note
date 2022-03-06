# D - トランプ挿入ソート

No	: 006  
url	: https://atcoder.jp/contests/abc006/tasks/abc006_4  
tag	: [[動的計画法]] [[最長増加部分列問題]] [[ソート]]  #ABC #blue

### idea
- LIS を求めたら，それに含まれないものは適切に挿入すればソートできる．
- 計算量は $\mathcal{O}(N \log N)$．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  vi lis;

  fore(x,a) {
    if(sz(lis)==0) lis.emplace_back(x);
    else {
      if(x>lis.back()) lis.emplace_back(x);
      else *lower_bound(all(lis),x)=x;
    }
  }

  cout<<n-sz(lis)<<endl;
}
```