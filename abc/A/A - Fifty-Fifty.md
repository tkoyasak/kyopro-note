# A - Fifty-Fifty

No	: 132  
url	: https://atcoder.jp/contests/abc132/tasks/abc132_a  
tag	: [[文字列操作]]  #ABC #gray

### idea
- c++ の string はソートできる．

### code
```cpp
int main(void)
{
	string s;
	cin>>s;

	sort(all(s));
	cout<<(s[0]==s[1]&&s[1]!=s[2]&&s[2]==s[3]?"Yes":"No")<<endl;
}
```