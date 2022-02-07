# E - Sequence Sum

No	: 179  
url	: https://atcoder.jp/contests/abc179/tasks/abc179_e  
tag	: [[整数問題]] [[ダブリング]]  #ABC #green

### idea
##### Method 1
- $f(x,m)$ のとり得る値は，高々 $m$ 個である．
- 周期性を利用して $\sum_{i=1}^{n} A_i$ を求めることができる．
- 計算量は $\mathcal{O}(M)$．
##### Method 2
- 次のテーブルを用意することで，ダブリングを用いて求めることができる．
	- $\text{next}[p][v] \coloneqq$ $v \pmod M$ から $2^p$ ステップ進んだ先の値．
	- $\text{sum}[p][v] \coloneqq$ $v \pmod M$ から $2^p$ 項分の総和．
- 計算量は $\mathcal{O}(M \log N)$．


### code
```cpp
// Method 1
int	main(void)
{
  ll n,x,m; cin>>n>>x>>m;
  vi id(m,-1);
  vl w(1,0);
  ll ans=0,len=0;

  while(id[x]==-1) {
    w.push_back(w[len]+x);
    id[x]=len++;
    (x*=x)%=m;
  }

  if(n<=len) {
    ans=w[n];
  }
  else {
    n-=len;
    ll t=len-id[x],q=n/t,r=n%t;
    ans+=w[len];
    ans+=(w[id[x]+t]-w[id[x]])*q;
    ans+=(w[id[x]+r]-w[id[x]]);
  }

  cout<<ans<<endl;
}
```

```cpp
// Method 2
int	main(void)
{
  const int D=40;
  ll n,x,m; cin>>n>>x>>m;
  vvl next(D+1,vl(m,-1)),sum(D+1,vl(m,0));
  ll ans=0;

  rep(i,m) {
    next[0][i]=1LL*i*i%m;
    sum[0][i]=i;
  }
  rep(p,D) rep(i,m) {
    next[p+1][i]=next[p][next[p][i]];
    sum[p+1][i]=sum[p][i]+sum[p][next[p][i]];
  }
  rrep(p,D,0) if(n&(1LL<<p)) {
    ans+=sum[p][x];
    x=next[p][x];
  }

  cout<<ans<<endl;
}
```