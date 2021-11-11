# B - Training Camp

No	: 055  
url	: https://atcoder.jp/contests/abc055/tasks/abc055_b  
tag	: [[整数論]] [[余り]]  #ABC #gray

### idea
- [「1000000007 で割ったあまり」の求め方を総特集！](https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a)

### code
```cpp
int main(void)
{
  ll n; cin>>n;
  ll mod=pow(10,9)+7;
  ll ans=1;

  reps(i,1,n+1) {
    ans*=i;
    ans%=mod;
  }

  cout<<ans<<endl;
}
```