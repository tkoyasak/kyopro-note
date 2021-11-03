# B - Shiritori

No	: 109  
url	: https://atcoder.jp/contests/abc109/tasks/abc109_b  
tag	: [[文字列操作]]  #ABC #gray

### idea
- 同じ単語が出たかどうかは，`set`を用いて管理する．

### code
```cpp  
int main(void)
{
  ll n;
  cin>>n;
  set<string> s;
  vector<string> ss(n);
  rep(i,n) {
    cin>>ss[i];
    s.insert(ss[i]);
  }

  bool ok=true;
  if(s.size()!=n) ok=false;

  char u=ss[0].front();
  rep(i,n) {
    if(u!=ss[i].front()) ok=false;
    u=ss[i].back();
  }

  YesNo(ok);
}
```