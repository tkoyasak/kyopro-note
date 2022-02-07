# B - Count Balls

No	: 158  
url	: https://atcoder.jp/contests/abc158/tasks/abc158_b  
tag	: [[整数判定]]  #ABC #gray

### idea

### code
```cpp
int main(void)
{
  ll n,a,b;
  cin>>n>>a>>b;
  ll sum=a+b;
  ll r=n%sum;
  n/=sum;
  ll ans=n*a+min(a,r);

  cout<<ans<<endl;
}
```