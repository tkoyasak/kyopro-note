# C - Unification

No	: 120  
url	: https://atcoder.jp/contests/abc120/tasks/abc120_c  
tag	: [[全探索]]  #ABC #gray

### idea
- すべての操作後は，０か１のみとなっている．
- 操作では０と１が１つずつ消えていく．
- 従ってキューブを取り除ける回数は $\text{min}($ 0の個数,1の個数 $)\times2$ となる．

### code
```cpp
int	main(void)
{
  string s; cin>>s;
  
  int cnt[2]={0,0};
  fore(c,s) cnt[c-'0']++;
  
  cout<<min(cnt[0],cnt[1])*2<<endl;
}
```