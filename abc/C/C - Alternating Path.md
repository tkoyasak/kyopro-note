# C - Alternating Path

No	: エイシング プログラミング コンテスト 2019  
url	: https://atcoder.jp/contests/aising2019/tasks/aising2019_c  
tag	: [[UnionFind]]  #ABC #cyan #解説AC 

### idea
- 各黒マスについて，そこから行ける白マスをすべて求めようとする(BFSなど)と，$O(H^2W^2)$ かかって地球が爆発してしまう．
- ある黒マス $u,v$ が白黒交互パスによって互いに行き来できるとき，次の個数は等しくなる．
	- $u$ から行くことのできる白マスの個数
	- $v$ から行くことのできる白マスの個数
- 各マスに対して「互いに行き来できる関係」ごとに分割する，すなわち，連結成分分解をすることが考えられる．
- 求める解は，連結成分ごとに $\text{黒マスの個数} \times \text{白マスの個数}$ を求めればいい．

### code
```cpp
int	main(void)
{
  int h,w; cin>>h>>w;
  vs s(h); rep(i,h) cin>>s[i];

  UnionFind uf(h*w);
  rep(i,h) rep(j,w) {
    int cur=i*w+j,u=(i+1)*w+j,v=i*w+j+1;
    if(i+1<h && s[i][j]!=s[i+1][j]) uf.unite(cur,u);
    if(j+1<w && s[i][j]!=s[i][j+1]) uf.unite(cur,v);
  }

  vi black(h*w),white(h*w);
  rep(i,h) rep(j,w) {
    int cur=i*w+j;
    if(s[i][j]=='#') black[uf.root(cur)]++;
    else white[uf.root(cur)]++;
  }

  ll ans=0;
  rep(i,h*w) ans+=1LL*black[i]*white[i];
  cout<<ans<<endl;
}
```