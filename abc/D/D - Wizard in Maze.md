# D - Wizard in Maze

No	: 176  
url	: https://atcoder.jp/contests/abc176/tasks/abc176_d  
tag	: [[幅優先探索]] [[01-BFS]]  #ABC #cyan #解説AC 

### idea
- [01-BFS について @betrue12](https://betrue12.hateblo.jp/entry/2018/12/08/000020)

### code
```cpp
int	main(void)
{
  int h,w; cin>>h>>w;
  int si,sj,ti,tj; cin>>si>>sj>>ti>>tj,si--,sj--,ti--,tj--;
  vs s(h); rep(i,h) cin>>s[i];
  vvi dist(h,vi(w,inf));
  deque<pii> q;

  auto inside=[&](int i,int j) {
    return 0<=i&&i<h&&0<=j&&j<w&&s[i][j]=='.';
  };

  dist[si][sj]=0;
  q.emplace_front(si,sj);
  while(!q.empty()) {
    auto [i,j]=q.front(); q.pop_front();
    reps(ci,i-2,i+3) reps(cj,j-2,j+3) if(inside(ci,cj)) {
      int warp=(abs(ci-i)+abs(cj-j)!=1);
      int d=dist[i][j]+warp;
      if(d<dist[ci][cj]) {
        dist[ci][cj]=d;
        if(warp) q.emplace_back(ci,cj);
        else q.emplace_front(ci,cj);
      }
    }
  }

  if(dist[ti][tj]==inf) cout<<-1<<endl;
  else cout<<dist[ti][tj]<<endl;
}
```