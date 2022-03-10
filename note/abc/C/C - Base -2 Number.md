# C - Base -2 Number

No	: 105  
url	: https://atcoder.jp/contests/abc105/tasks/abc105_c  
tag	: [[整数問題]] [[Bit]]  #ABC #cyan

### idea
- [解説記事 @drken](https://drken1215.hatenablog.com/entry/2018/08/13/123600)

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  string ans;

  if(n==0) ans="0";
  while(n) {
    int r=abs(n%(-2));
    ans+=(char)(r+'0');
    n-=r;
    n/=-2;
  }

  rev(ans);
  cout<<ans<<endl;
}
```