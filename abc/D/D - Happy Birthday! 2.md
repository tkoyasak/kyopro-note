# D - Happy Birthday! 2

No	: 200  
url	: https://atcoder.jp/contests/abc200/tasks/abc200_d  
tag	: [[全探索]] [[部分和]] [[鳩の巣原理]]  #ABC #cyan #解説AC

### idea
- 数列 $B$ ( または $C$ ) の候補を $201$ 通り探索すれば，その中で必ず条件を満たす数列の組を見つけることができる．
> 鳩の巣原理
> - $X+1$ 羽の鳩を $X$ 個の鳥籠に入れるとき，２羽以上の鳩が入った鳥籠が少なくとも１つ以上存在する．
- 数列の候補は $2^N-1$ 通りあるので，$N \ge 8$ のケースでは必ず答えが存在する．

### code
```cpp
int	main(void)
{
  const int M=200;
  int n; cin>>n;
  vi a(n),s(M); rep(i,n) cin>>a[i];

  auto output=[&](int mask) {
    cout<<__builtin_popcount(mask)<<" ";
    rep(i,n) if(mask>>i&1) cout<<i+1<<" ";
    cout<<endl;
  };

  chmin(n,8);
  reps(mask,1,1<<n) {
    int x=0;
    rep(i,n) if(mask>>i&1) (x+=a[i])%=M;
    if(s[x]==0) s[x]=mask;
    else {
      cout<<"Yes"<<endl;
      output(s[x]);
      output(mask);
      return 0;
    }
  }
  cout<<"No"<<endl;
}
```