# D - Send More Money

No	: 198  
url	: https://atcoder.jp/contests/abc198/tasks/abc198_d  
tag	: [[全探索]]  #ABC #cyan #解説AC 

### idea
- 問題文に次のようにあり割り当てられる数字は高々 $0 \sim 9$ の10通りなので，文字が11種類以上あるときは明らかに `UNSOLVABLE` となる．
> - $S_i$ の $x$ 文字目と $S_j$ の $y$ 文字目が等しいとき，またその時に限り，$N'_i$ の $x$ 文字目と $N'_j$ の $y$ 文字目が等しい
- 覆面算を真面目に解くよりも，どの文字にどの数字を割り当てるかを全探索し，各割り当て方について $N_1+N_2=N_3$ を満たしているか確かめる方が実装が容易．
- 探索の手順は次の通り．
	- $S_1$，$S_2$，$S_3$ から文字を抽出し，各文字にインデックス($0 \sim 9$) を割り当てる．(座標圧縮)
	- 数字の割り当て方を全探索する．
- 数字の割り当て方は $10!=3628800$ 通り．計算量は $\mathcal{O}(10!)$．

### code
```cpp
int	main(void)
{
  vs s(3); rep(i,3) cin>>s[i];

  // 11種類以上あったらNG
  set<char> chars;
  rep(i,3) rep(j,sz(s[i])) chars.insert(s[i][j]);
  if(sz(chars)>10) {
    cout<<"UNSOLVABLE"<<endl;
    return 0;
  }

  // 座標圧縮
  vi comp(26);
  int cnt=0;
  fore(ch,chars) comp[ch-'a']=cnt++;
  rep(i,3) rep(j,sz(s[i])) s[i][j]=comp[s[i][j]-'a'];

  // 全探索
  vi p(10); iota(all(p),0);
  do {
    if(p[s[0][0]]==0||p[s[1][0]]==0||p[s[2][0]]==0) continue;
    vl num(3);
    rep(i,3) rep(j,sz(s[i])) num[i]=num[i]*10+p[s[i][j]];
    if(num[0]+num[1]==num[2]) {
      rep(i,3) cout<<num[i]<<endl;
      return 0;
    }
  } while(next_permutation(all(p)));

  cout<<"UNSOLVABLE"<<endl;
}
```