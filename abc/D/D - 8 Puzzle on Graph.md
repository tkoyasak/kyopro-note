# D - 8 Puzzle on Graph

No	: 224  
url	: https://atcoder.jp/contests/abc224/tasks/abc224_d  
com	: https://youtu.be/KMsEXLe_8go?t=1930  
tag	: [[幅優先探索]] [[グラフ]] #ABC #cyan #解説AC 

### idea
- ８コマの配置を文字列 $s_0s_1\dots s_8$ で表現する．
	- 0-indexed で表す．
	- 頂点 $i$ にコマ $j$ が置かれているとき $s_i=j$ とする．
	- 頂点 $i$ が空の頂点のとき $s_i=9$ とする．
- 完成した文字列の配置は，文字列 `012345679` で表される．
- コマの配置は９文字の並び替えで表されるため．コマの配置の総数は $9!$ 通り．
- 幅優先探索の過程で「初期状態から各状態 $s_0s_1\dots s_8$ への最短距離」を記憶するためには，文字列 $s_0s_1\dots s_8$ に対して最短距離を対応させる連想配列を用いることができる．

### code
```cpp
int	main(void)
{
  const string P="012345679";
  int m; cin>>m;
  vi g[9];
  rep(m) {
    int u,v; cin>>u>>v; u--,v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  string s=string(9,'9');
  rep(i,8) {
    int p; cin>>p; p--;
    s[p]=i+'0';
  }

  queue<string> q;
  q.push(s);
  map<string,int> mp;
  mp[s]=0;

  while(!q.empty()) {
    s=q.front(); q.pop();
    int v=s.find('9');

    fore(u,g[v]) {
      string t=s;
      swap(t[u],t[v]);
      if(mp.count(t)) continue;
      mp[t]=mp[s]+1;
      q.push(t);
    }
  }

  if(mp.count(P)) cout<<mp[P]<<endl;
  else cout<<-1<<endl; 
}
```