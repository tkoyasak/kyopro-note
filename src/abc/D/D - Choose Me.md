# D - Choose Me

No	: 187  
url	: https://atcoder.jp/contests/abc187/tasks/abc187_d  
tag	: [[ソート]]  #ABC #brown

### idea
- $\text{d} \coloneqq$ (高橋氏の得る票数) - (青木氏の得る票数)，と定義すると以下がわかる．
	- $i$ 番目の町で新たに演説すると，$\text{d}$ は $2A_i+B_i$ 増える．
	- $\text{d} \gt 0$ になると高橋氏が青木氏より多くの票を獲得する．
- 計算量は $\mathcal{O}(N \log N)$ ．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vll f(n);
  ll d=0;
  rep(i,n) {
    ll a,b; cin>>a>>b;
    d-=a;
    f[i]=2*a+b;
  }
  int ans=0;

  sort(rall(f));
  while(d<=0) d+=f[ans++];

  cout<<ans<<endl;
}
```