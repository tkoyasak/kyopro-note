# C - Ringo's Favorite Numbers 2

No	: 200  
url	: https://atcoder.jp/contests/abc200/tasks/abc200_c  
tag	: [[余り]]  #ABC #gray

### idea
- 「$A_i - A_j$ が200の倍数である」ことは，「$A_i$ を200で割った余りと $A_j$ を200で割った余りが等しい」といえる．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vi a(n);
  map<int,ll> b;
  rep(i,n) {
    cin>>a[i];
    b[a[i]%200]++;
  }

  ll ans=0;
  for(auto &[n,m]:b) ans+=m*(m-1)/2;

  cout<<ans<<endl;
}
```