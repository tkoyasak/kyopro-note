# D - Handstand 2

No	: 152  
url	: https://atcoder.jp/contests/abc152/tasks/abc152_d  
tag	: [[数え上げ問題]]  #ABC #green

### idea
- $A$ を固定したときの $B$ の個数は，$A$ の「先頭の桁」と「末尾の桁」のみに依存する．
- 計算量は $\mathcal{O}(N)$．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  vvi cnt(10,vi(10,0));
  int ans=0;

  reps(i,1,n+1) {
    string s=to_string(i);
    int top=s.front()-'0',btm=s.back()-'0';
    cnt[top][btm]++;
  }
  rep(top,10) rep(btm,10) ans+=cnt[top][btm]*cnt[btm][top];

  cout<<ans<<endl;
}
```