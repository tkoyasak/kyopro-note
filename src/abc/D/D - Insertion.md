# D - Insertion

No	: 064  
url	: https://atcoder.jp/contests/abc064/tasks/abc064_d  
tag	: [[文字列操作]]  #ABC #green

### idea
- 括弧列の整合性については，次の定番の考え方がある．
	- `stack` を用意する．
	- 左括弧がきたら，`stack` に追加．
	- 右括弧がきたら，
		1. `stack` が空のとき，不整合となる．
		2. `stack` が空でないときは，`stack` にある左括弧と右括弧をペアとして `stack` から pop する．
	- 不整合のパターンは，
		1.  途中で `stack` が空なのに右括弧がくる．
		2. 最後に `stack` の左括弧が余る．

### code
```cpp
int	main(void)
{
  int n; cin>>n;
  string s; cin>>s;
  int l=0,r=0;

  rep(i,n) {
    if(s[i]=='(') l++;
    else if(l>0) l--;
    else r++;
  }

  cout<<string(r,'(')<<s<<string(l,')')<<endl;
} 
```