# E - (∀x∀)

No	: 242  
url	: https://atcoder.jp/contests/abc242/tasks/abc242_e  
com	:
tag	: [[動的計画法]] [[桁DP]]  #ABC #cyan #解説AC  

### idea
- 長さ $N$ の回文は，先頭 $\lceil \frac{N}{2} \rceil$ 文字が分かれば一意に定まる．
- $M=\lceil \frac{N}{2} \rceil$ とおく．
- まず，$X \lt S$ となる文字列を数える．
- 文字列 $S$ の $i$ 文字目が $X$ であるとき，回文は $i$ 文字目が $X$ より小さい文字ならば $S$ より辞書順で小さくなる．
- このとき，できる文字列は $(X-1) \times 26^{M-i}$ 通り．
- 最後に $M$ まで $S$ と同じ文字列が $X \le S$ を満たすか判定する．

### code
```cpp
int	main(void)
{
  int q; cin>>q;

  rep(q) {
    int n; string s; cin>>n>>s;
    mint ans=0;
    int m=(n+1)/2;

    rep(i,m) {
      ans*=26;
      ans+=s[i]-'A';
    }

    string t=s;
    rep(i,m) t[n-i-1]=s[i];
    if(t<=s) ans++;

    cout<<ans.val()<<endl;
  }
}
```
