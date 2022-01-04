# D - Restricted Permutation

No	: 223
url	: https://atcoder.jp/contests/abc223/tasks/abc223_d  
tag	: [[トポロジカルソート]] [[DAG]]  #ABC #green

### idea
- $N$ 頂点の有向グラフであって、各 $i$ $(1 \le i \le M)$ について，頂点 $A_i$ から頂点 $B_i$ に辺が張られているようなものを考えると、トポロジカルソートした結果として辞書順最小のものが答えとなる．
- 処理の流れは次の通り．
  - 空の数列 $S$ を用意する．
  - 入次数が $0$ の頂点が存在する間，以下の処理を繰り返す．
    - 入次数が $0$ の頂点を１つ選び，$u$ とする．
    - $S$ の末尾に $u$ を追加する．
    - $u$ および $u$ から出ている辺をグラフから削除する．
  - 以上の処理が終了した時点で，
    - グラフに頂点が残っているならば，トポロジカルソートすることは不可能．
    - グラフに頂点が残っていなければ，$S$ がトポロジカルソートした結果となっている．

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  vvi to(n);
  vi indeg(n,0);
  rep(i,m) {
    int a,b; cin>>a>>b; a--; b--;
    to[a].push_back(b);
    indeg[b]++;
  }
  priority_queue<int,vi,greater<int>> q;
  vi ans;

  rep(i,n) if(indeg[i]==0) q.push(i);
  while(!q.empty()) {
    int v=q.top(); q.pop();
    ans.push_back(v+1);
    fore(u,to[v]) {
      indeg[u]--;
      if(indeg[u]==0) q.push(u);
    }
  }

  if(sz(ans)!=n) cout<<-1<<endl;
  else rep(i,n) cout<<ans[i]<<endl;
}
```