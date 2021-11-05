# B - 美しい文字列

No	: 044  
url	: https://atcoder.jp/contests/abc044/tasks/abc044_b  
tag	: [[全探索]]  #ABC #gray

### idea
- 英小文字 ( 'a' ~ 'z' ) について判定を行うと良い．

### code
```cpp
int	main(void)
{
  string s;
  cin>>s;
  bool ok=true;

  reps(i,'a','z'+1) {
    int cnt=0;
    rep(j,s,size()) if(i==s[j]) cnt++;
    if(cnt%2==1) {
      ok=false;
      break;
    }
  }

  YesNo(ok);
}
```