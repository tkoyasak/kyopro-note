# C - Travel

No	: 183  
url	: https://atcoder.jp/contests/abc183/tasks/abc183_c  
tag	: [[全探索]]  #ABC #gray

### idea
- 都市の順列の全探索には $\text{next_permutation}$ を用いるとよい．

### code
```cpp
int	main(void)
{
  int n,k; cin>>n>>k;
  int t[n][n]; rep(i,n) rep(j,n) cin>>t[i][j];
  vi city; reps(i,1,n) city.push_back(i);
  int ans=0;

  do {
    int cnt=t[0][city.front()];
    rep(i,n-2) cnt+=t[city[i]][city[i+1]];
    cnt+=t[city.back()][0];
    if(cnt==k) ans++;
  } while(next_permutation(all(city)));

  cout<<ans<<endl;
}
```