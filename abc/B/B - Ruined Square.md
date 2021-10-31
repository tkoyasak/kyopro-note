# B - Ruined Square

No	: 108  
url	: https://atcoder.jp/contests/abc108/tasks/abc108_b  
tag	: [[行列]]  #ABC #gray

### idea
- 回転行列を用いる
- $dx=x_2-x_1，dy=y_2-y_1$なるベクトル$(dx,dy)$を考える．
- $(x_2,y_2)$から$(x_3,y_3)$へのベクトルは，反時計回りに90度回転したもの，すなわち$(-dy,dx)$となる．よって以下となる．
$$(x_3,y_3)=(x_2-dy,y_2+dx)$$
$$(x_4,y_4)=(x_1-dy,y_1+dx)$$

### code
```cpp
int main(void)
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;

	int dx=x2-x1;
	int dy=y2-y1;

	cout<<x2-dy<<" "<<y2+dx<<" "<<x1-dy<<" "<<y1+dx<<endl;
}
```