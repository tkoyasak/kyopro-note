# C - Mandarin Orange

No	: 189  
url	: https://atcoder.jp/contests/abc189/tasks/abc189_c  
tag	: [[最大長方形問題]]  #ABC #brown

### idea
- ヒストグラムの中の最大長方形を求める問題に帰着できる．
- 計算量は均すと $\mathcal{O}(N)$ となる．

### code
```cpp
void get_stairs(vi &a, int &n, vi &ls, vi &rs) {
  stack<pair<int,int>> ps;

  ps.emplace(0,-1);
  rep(i,n) {
    while(ps.top().first>=a[i]) ps.pop();
    ls[i]=ps.top().second;
    ps.emplace(a[i],i);
  }
  while(!ps.empty()) ps.pop();
  ps.emplace(0,n);
  rrep(i,n-1,0) {
    while(ps.top().first>=a[i]) ps.pop();
    rs[i]=ps.top().second;
    ps.emplace(a[i],i);
  }
}

int	main(void)
{
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  vi ls(n),rs(n);
  int ans=0;

  get_stairs(a,n,ls,rs);
  rep(i,n) chmax(ans,a[i]*(rs[i]-ls[i]-1));
  cout<<ans<<endl;
}
```