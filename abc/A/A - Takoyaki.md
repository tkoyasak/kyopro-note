# A - Takoyaki

No	: 176  
url	: https://atcoder.jp/contests/abc176/tasks/abc176_a  
tag	: [[整数判定]]  #ABC #gray 

### idea
- たこ焼きを焼く回数は，切り捨てが発生したときのみ+1を行う．
- これは以下のようにも表現できる．ちょうど割り切れるとき以外は+1になる．
	`times = (N+X-1)/X`


### code
```cpp
int	mian(void)
{
  int N,X,T;
  cin>>N>>X>>T;
  int tiles = (N+X-1)/X;

  cout<<times*T<<endl;
}
```