# E - Mex Min

No	: 194  
url	: https://atcoder.jp/contests/abc194/tasks/abc194_e  
tag	: [[尺取り法]]  #ABC #green

### idea
##### Method 1
- $A_i$ の出現位置をメモしておく．
- $0$ からチェックして，出現位置間の距離が $M$ 以上となれば，$\text{mex}$ の最小値となる．
- 計算量は $\mathcal{O}(N)$．
##### Method 2
- 直近の $A_i$ の出現位置をメモしておく．
- 計算量は $\mathcal{O}(N)$．
##### Method 3
- $A_i$ の出現回数をメモしておく．
- $\text{mex}$ の値を小さい方にのみ更新する．
- 計算量は $\mathcal{O}(N)$．

### code
```cpp
// Method 1
int	main(void)
{
  int n,m; cin>>n>>m;
  vvi pos(n);
  rep(i,n) {
    int a; cin>>a;
    pos[a].emplace_back(i);
  }

  rep(i,n) {
    pos[i].emplace_back(n);
    int pre=-1;
    fore(j,pos[i]) {
      if(j-pre>m) {
        cout<<i<<endl;
        return 0;
      }
      pre=j;
    }
  }
  cout<<n<<endl;
}
```

```cpp
// Method 2
int	main(void)
{
  int n,m; cin>>n>>m;
  vi pre(n,-1);
  int ans=n;

  rep(i,n) {
    int a; cin>>a;
    if(i-pre[a]>m) chmin(ans,a);
    pre[a]=i;
  }
  rep(i,n) if(n-pre[i]>m) chmin(ans,i);

  cout<<ans<<endl;
}
```

```cpp
// Method 3
int	main(void)
{
  int n,m; cin>>n>>m;
  vi a(n); rep(i,n) cin>>a[i];
  vi cnt(n+1,0);
  int ans=0;

  rep(i,m) cnt[a[i]]++;
  while(cnt[ans]) ans++;
  reps(r,m,n) {
    cnt[a[r]]++; cnt[a[r-m]]--;
    int l=a[r-m];
    if(!cnt[l]) chmin(ans,l);
  }

  cout<<ans<<endl;
}
```