# E - Unique Color

No	: 198  
url	: https://atcoder.jp/contests/abc198/tasks/abc198_e  
tag	: [[深さ優先探索]] [[木構造]]  #ABC #green

### idea
- 深さ優先探索の探索順序である「行きがけ順」「帰りがけ順」をイメージできていると解きやすい．
- 「頂点1からいまいる頂点までの経路上に存在する各色の頂点の個数」の配列を用意しておき、頂点への進入/退出時にこれを更新すればよい

### code
```cpp
const int M=100001;
int color[M],cnt[M];
vvi g;
vi ans;

void dfs(int v,int p) {
  int c=color[v];
  cnt[c]++;
  if(cnt[c]==1) ans.push_back(v+1);
  fore(u,g[v]) if(u!=p) dfs(u,v);
  cnt[c]--;
}

int	main(void)
{
  int n; cin>>n;
  rep(i,n) cin>>color[i];
  g.resize(n);
  rep(i,n-1) {
    int a,b; cin>>a>>b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0,-1);

  sort(all(ans));
  fore(i,ans) cout<<i<<endl;
}
```