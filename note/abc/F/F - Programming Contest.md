# F - Programming Contest

No	: 184  
url	: https://atcoder.jp/contests/abc184/tasks/abc184_f  
com	: https://youtu.be/iWS5WCvMMak?t=6300  
tag	: [[半分全列挙]] [[部分和]]  #ABC #cyan #解説AC  

### idea

### code
```cpp
int main(void)
{
  int n; ll t; cin>>n>>t;
  vl a(n); fore(i,a) cin>>i;

  // 半分全列挙
  vl u{0},v{0};
  rep(i,n) {
    per(j,sz(u)) u.pb(u[j]+a[i]);
    swap(u,v);
  }
  srt(u);

  ll ans=0;
  fore(x,v) {
    if(x>t) continue;
    auto it=upper_bound(all(u),t-x);
    chmax(ans,x+*--it);
  }
  cout<<ans<<endl;
}
```