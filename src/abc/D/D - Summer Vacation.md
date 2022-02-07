# D - Summer Vacation

No	: 137  
url	: https://atcoder.jp/contests/abc137/tasks/abc137_d  
com	: https://youtu.be/1Z6ofKN03_Y?t=3508  
tag	: [[貪欲法]]  #ABC #cyan #解説AC 

### idea
- 問題文から得られる考察．
	- 各アルバイトをいつまでに始めればいいのかを考える．
			$\Rightarrow$ $A_i$ の値が小さいほど自由度が高い．
	- 最終日に選べるアルバイトは $A_i=1$ のみ．最終 $-1$ 日に選べるアルバイトは $A_i\le2$．$\ldots$ となる．
			$\Rightarrow$ $M$ 日後までに報酬を得る必要があるので，$M$ 日後から $i(1 \le i \le M)$ 日前には $A_j \le i$ となるアルバイトしか選べない． 
- 解法としては貪欲法．振り込みまでの期間が長いものから順に選んでいく．

### code
```cpp
int	main(void)
{
  int n,m; cin>>n>>m;
  vvi jobs(m);
  rep(i,n) {
    int a,b; cin>>a>>b;
    if(a>m) continue;
    jobs[m-a].pb(b);
  }
  priority_queue<int> pq;
  ll ans=0;

  rrep(i,m-1,0) {
    fore(b,jobs[i]) pq.push(b);
    if(!pq.empty()) {
      ans+=pq.top();
      pq.pop();
    }
  }

  cout<<ans<<endl;
}
```