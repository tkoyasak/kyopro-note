# D - Linear Probing

No	: 228  
url	: https://atcoder.jp/contests/abc228/tasks/abc228_d  
tag	: [[深さ優先探索]] [[UnionFind]]  #ABC #green

### idea
- 愚直に処理を行うと，例えば次のケースで計算量が $O(Q^2)$ となる．
	- すべてのクエリに対して $t_i=1$ かつ $x_i \mod N =0$ である．

##### Method 1 (Set)
- まだ $A_i=-1$ である $i$ を `std::set` で保持しておく．
- 計算量は $O(N+Q \log Q)$．

##### Method 2 (経路圧縮)
- $0 \le h \lt N$ に対し，$h$ を $1$ ずつ増やしていき，初めて $A_{h\mod N}=-1$ になったときの $h \mod N$ の値を $p(h)$ と表す．
- $p(h)$ を求めるのは，次のように行う．
	- $A_h\neq -1$ である間，$h \leftarrow p(h)$ を繰り返す．
	- $A_k=-1$ を $-1$ でない値に書き換えるとき，$p(k)\leftarrow p(k+1)$ と更新する．
- 計算量は $O(N + Q \log N)$．

### code
```cpp
// Method 1
int	main(void)
{
  const int N=1<<20;
  vl a(N,-1);
  int q; cin>>q;
  set<int> s; rep(i,N) s.insert(i);

  rep(i,q) {
    int t; ll x; cin>>t>>x;
    if(t==1) {
      int j=x%N;
      auto it=s.lower_bound(j);
      if(it==s.end()) it=s.begin();
      a[*it]=x;
      s.erase(it);
    }
    else cout<<a[x%N]<<endl;
  }
}
```
```cpp
// Method 2
int	main(void)
{
  const int N=1<<20;
  int q; cin>>q;
  vl a(N,-1);
  vi p(N); iota(all(p),0);

  auto find=[&](auto&& self,int x) {
    if(p[x]==x) return x;
    else return p[x]=self(self,p[x]);
  };

  rep(i,q) {
    int t; ll x; cin>>t>>x;
    if(t==1) {
      int j=find(find,x%N);
      a[j]=x;
      p[j]=find(find,(j+1)%N);
    }
    else cout<<a[x%N]<<endl;
  }
}
```