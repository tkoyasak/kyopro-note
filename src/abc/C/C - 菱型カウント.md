# C - 菱型カウント

No	: 018  
url	: https://atcoder.jp/contests/abc018/tasks/abc018_3  
tag	: [[Grid]] [[いもす法]]  #ABC #cyan #解説AC 

### idea
- $\text{imos}[i][j] \coloneqq$ $(i,j)$ を中心として菱形を作成したとき，その範囲内に存在する `x` 印の個数，と定義する．
- すべての $(i,j)$ についてカウントすると $\mathcal{O}(HWK^2)$ となりカップラーメンがのびのびになる．
- いもす法を用いて次のように $\text{imos}$ を更新する．
	- $(i,j)$ が `x` 印だったとき，$l(-k \lt l \lt k)$ について
		- $\text{imos}[i+l][\max{(0,j-k+|l|+1)}]$ には $1$ を足す．
		- $\text{imos}[i+l][\min{(w,j+k-|l|)}]$ からは $1$ を引く．
	- 最後に行方向に累積和をとると，$\text{imos}$ を完成させることができる．
- 計算量は $\mathcal{O}(HWK)$．

### code
```cpp
int	main(void)
{
  int h,w,k; cin>>h>>w>>k;
  vvi imos(h+1,vi(w+1));

  // いもす法
  rep(i,h) rep(j,w) {
    char c; cin>>c;
    if(c=='x') {
      reps(l,-k+1,k) if(0<=i+l && i+l<h) {
        int d=abs(l);
        imos[i+l][max(0,j-k+1+d)]++;
        imos[i+l][min(w,j+k-d)]--;
      }
    }
  }
  rep(i,h) reps(j,1,w) imos[i][j]+=imos[i][j-1];

  int ans=0;
  reps(i,k-1,h-k+1) reps(j,k-1,w-k+1) {
    if(imos[i][j]==0) ans++;
  }
  cout<<ans<<endl;
}

```