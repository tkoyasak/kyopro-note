# A - Still TBD

No	: 119  
url	: https://atcoder.jp/contests/abc119/tasks/abc119_a  
tag	: [[文字列比較]]  #ABC #gray 

### idea
- `scanf()`を利用すると，整数型として読み取れる．

### code
```cpp
int main(void)
{
	int y,m,d;
	scanf("%d/%d/%d",&y,&m,&d);

	using T = tuple<int, int, int>;
	T cur(y,m,d),hei(2019,4,30);
	cout<<(cur<=hei?"Heisei":"TBD")<<endl;
}
```