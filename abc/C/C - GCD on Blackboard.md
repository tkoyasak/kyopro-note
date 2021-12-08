# C - GCD on Blackboard

No	: 125  
url	: https://atcoder.jp/contests/abc125/tasks/abc125_c  
tag	: [[整数]]  #ABC #green

### idea
- [解説配信 @snuke](https://youtu.be/8lm8o8L9Bmw)
- 前処理として，左区間/右区間の累積GCDを求めておく．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  vi l(n),r(n);
  int ans=1;

  rep(i,n-1) l[i+1]=gcd(l[i],a[i]);
  rrep(i,n-1,1) r[i-1]=gcd(r[i],a[i]);
  rep(i,n) chmax(ans,gcd(l[i],r[i]));

  cout<<ans<<endl;
}
```

```cpp
int	main(void)
{
  int n; cin>>n;
  set<int> s;
  int g=0;

  rep(i,n) {
    int a; cin>>a;
    set<int> t; swap(s,t);
    fore(x,t) s.insert(gcd(x,a));
    s.insert(g);
    g=gcd(g,a);
  }

  cout<<*s.rbegin()<<endl;
}
```
