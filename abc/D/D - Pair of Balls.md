# D - Pair of Balls

No	: 216  
url	: https://atcoder.jp/contests/abc216/tasks/abc216_d  
tag	: [[貪欲]] [[トポロジカルソート]]  #ABC #green

### idea

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  vector<queue<int>> v(m);
  vvi pos(n);
  rep(i,m) {
    int k; cin>>k;
    rep(j,k) {
      int x; cin>>x; x--;
      v[i].push(x);
      pos[x].push_back(i);
    }
  }
  vi cnt(n,0);
  queue<int> q;

  rep(i,m) {
    int x=v[i].front(); cnt[x]++;
    if(cnt[x]==2) q.push(x);
  }
  while(!q.empty()) {
    int x=q.front(); q.pop(); n--;
    fore(i,pos[x]) {
      v[i].pop();
      if(!v[i].empty()) {
        int y=v[i].front(); cnt[y]++;
        if(cnt[y]==2) q.push(y);
      }
    }
  }

  YesNo(!n);
}
```

```cpp
vi tpl_sort(vector<vi>& g,int n) {
  vi indeg(n,0),order;
  queue<int> q;

  rep(i,n) fore(j,g[i]) indeg[j]++;
  rep(i,n) if(indeg[i]==0) q.push(i);
  while(!q.empty()) {
    int v=q.front(); q.pop();
    order.push_back(v);
    fore(u,g[v]) {
      indeg[u]--;
      if(indeg[u]==0) q.push(u);
    }
  }

  return order;
}

int	main(void)
{
  int n,m; cin>>n>>m;
  vvi v(m),g(n);
  rep(i,m) {
    int k; cin>>k; v[i]=vi(k);
    rep(j,k) cin>>v[i][j],v[i][j]--;
  }

  rep(i,m) rep(j,v[i].size()-1) g[v[i][j]].push_back(v[i][j+1]);

  YesNo(tpl_sort(g,n).size()==n);
}
```