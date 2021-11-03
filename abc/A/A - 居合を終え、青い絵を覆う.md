# A - 居合を終え、青い絵を覆う

No	: 49  
url	: https://atcoder.jp/contests/abc049/tasks/abc049_a  
tag	: [[文字列操作]]  #ABC #gray

### idea

### code
```cpp
int	main(void)
{
  char c;
  cin>>c;
  const string s="aeiou";

  cout<<s.find(c)==string::npos?"vowel":"consonant"<<endl;
}
```