# D - aab aba baa

No	: 202  
url	: https://atcoder.jp/contests/abc202/tasks/abc202_d  
tag	: [[組み合わせ]]  #ABC #green

### idea
- 辞書順が関係する問題では，前の文字から決めていくのが定石．
- 答えの先頭が `a` or `b` であるかの判定は次のように行う．
	- 先頭が `a` であるような文字列の総数が $K$ 個以上なら `a`．
	- そうでないなら `b`．

### code
```cpp
ll c[61][61];
int	main(void)
{
  int a,b; cin>>a>>b;
  ll k; cin>>k;
  string ans;

  c[0][0]=1;
  rep(i,60) rep(j,i+1) {
    c[i+1][j]+=c[i][j];
    c[i+1][j+1]+=c[i][j];
  }
  while(a+b>0) {
    ll x=0;
    if(a>0) x=c[a+b-1][a-1];
    if(k<=x) {
      ans+='a'; a--;
    }
    else {
      ans+='b'; b--;
      k-=x;
    }
  }

  cout<<ans<<endl;
}
```