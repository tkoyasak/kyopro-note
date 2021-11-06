# B - Guidebook

No	: 128  
url	: https://atcoder.jp/contests/abc128/tasks/abc128_b  
tag	: [[ソート]]  #ABC #gray

### idea
- C++ では，ソート時に独自の比較関数を与えることができる．
- 市名が異なれば市名の昇順，市名が同じならば点数の降順でソートする．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vs s(n); vi p(n); rep(i,n) cin>>s[i]>>p[i];
  vi ans;

  rep(i,n) ans.push_back(i);
  sort(all(ans),[&](int a,int b){
    if(s[a]!=s[b]) return s[a]<s[b];
    else return p[a]>p[b];
  });

  fore(i,ans) cout<<i+1<<endl;
}
```

```cpp
int	main(void)
{
  ll n; cin>>n;
  vector<tuple<string,int,int>> ans;

  rep(i,n) {
    string s; int a; cin>>s>>a;
    ans.push_back(make_tuple(s,-a,i+1));
  }
  sort(all(ans));

  rep(i,n) cout<<get<2>(ans[i])<<endl;
}
```