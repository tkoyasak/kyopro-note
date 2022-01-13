# D - Lunlun Number

No	: 161  
url	: https://atcoder.jp/contests/abc161/tasks/abc161_d  
tag	: [[深さ優先探索]]  #ABC #green

### idea
- [解説記事 @drken](https://drken1215.hatenablog.com/entry/2020/04/05/150900)
- 「$K$ 番目に小さい値を求めよ」という問題で `std::priority_queue` を使えるケースは多い，とのこと．

### code
```cpp
int	main(void)
{
  int k; cin>>k;
  queue<ll> q;

  reps(i,1,10) q.push(i);
  rep(i,k-1) {
    ll x=q.front(); q.pop();
    reps(j,-1,2) {
      int y=x%10+j;
      if(y>=0 && y<=9) q.push(x*10+y);
    }
  }

  cout<<q.front()<<endl;
}
```

```cpp
void	dfs(ll x,int cur,int d,vll& ans) {
  if(cur==d) {
    ans.push_back(x);
    return;
  }

  int z=x%10;
  reps(i,-1,2) {
    int y=z+i;
    if(y<0 || y>9) continue;
    dfs(x*10+y,cur+1,d,ans);
  }
}
 
int	main(void)
{
  int k; cin>>k;
  vll ans;
 
  reps(d,1,11) reps(x,1,10) {
    dfs(x,1,d,ans);
    if(sz(ans)>=k) {
      cout<<ans[k-1]<<endl;
      return 0;
    }
  }
}
```