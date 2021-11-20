# C - Tour

No	: 204  
url	: https://atcoder.jp/contests/abc204/tasks/abc204_c  
tag	: [[幅優先探索]]  #ABC #brown

### idea
- スタート地点から到達できる都市を探索すると，計算量は $O(N+M)$ となる．
- スタート地点は $N$ 通りので，これを全探索すると，計算量は $O(N(N+M))$ となる．

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  vector<vi> g(n);
  rep(i,m){
    int a,b; cin>>a>>b;
    g[a-1].push_back(b-1);
  }
  ll ans=0;

  rep(i,n) {
    queue<int> que;
    set<int> seen;

    que.push(i);
    seen.emplace(i);
    while(!que.empty()) {
      int v=que.front(); que.pop();
      fore(w,g[v]) {
        if(seen.count(w)) continue;
        seen.emplace(w);
        que.push(w);
      }
    }
    ans+=seen.size();
  }

  cout<<ans<<endl;
}
```