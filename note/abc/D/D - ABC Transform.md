# D - ABC Transform

No	: 242  
url	: https://atcoder.jp/contests/abc242/tasks/abc242_d  
com	: https://youtu.be/hdkrWya61Ds?t=3737  
tag	: [[周期性]] [[Bit]] #ABC #cyan #解説AC  

### idea
##### Method snuke
- 文字列の位置は２進数で表したとき，$1$ の個数は右に進む回数になる．

##### Method unidayo
- [【AtCoder解説】PythonでABC242のA,B,C,D,E問題を制する！](https://qiita.com/u2dayo/items/465c9299755ed20ee4d3#d%E5%95%8F%E9%A1%8Cabc-transform)

### code
```cpp
// Method snuke
int	main(void)
{
  string s; int q; cin>>s>>q;

  rep(q) {
    ll t,k; cin>>t>>k; k--;
    int pos=0;
    if(t<61) {
      pos=k/bit(t);
      k%=bit(t);
    }
    ll r=pcnt(k);
    ll l=t-r;
    ll x=l+r*2+(s[pos]-'A');
    char ans='A'+(x%3);
    cout<<ans<<endl;
  }
}
```

```cpp
// Method unidayo
ll solve(string& s,ll t,ll k) {
  if(t==0) return s[k]-'A';
  if(k==0) return (s[0]-'A')+t;
  if(k%2==0) return solve(s,t-1,k/2)+1;
  else return solve(s,t-1,k/2)+2;
}

int	main(void)
{
  string s; int q; cin>>s>>q;

  rep(q) {
    ll t,k; cin>>t>>k; k--;

    char ans='A'+solve(s,t,k)%3;
    cout<<ans<<endl;
  }
}
```