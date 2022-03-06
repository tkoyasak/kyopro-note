# C - 倍々ゲーム

No	: 027  
url	: https://atcoder.jp/contests/abc027/tasks/abc027_c  
tag	: [[構築]] [[木構造]] #ABC #cyan #解説AC 

### idea
- [Editorial](https://www.slideshare.net/chokudai/abc027)
- 深さが偶数のとき，高橋くん：左，青木くん：右 に動かしたい．
- 深さが奇数のとき，高橋くん：右，青木くん：左 に動かしたい．


### code
```cpp
int	main(void)
{
  ll n; cin>>n;
  int depth=0;

  // Ｎの深さを求める
  rep(i,64) if(n&bit(i)) depth=i+1;

  ll x=1;
  rep(i,depth) {
    bool is_aoki=i&1;
    if(depth&1) {
      if(is_aoki) x=x*2;
      else x=x*2+1;
    }
    else {
      if(is_aoki) x=x*2+1;
      else x=x*2;
    }
    if(x>n) {
      if(is_aoki) cout<<"Takahashi"<<endl;
      else cout<<"Aoki"<<endl;
      return 0;
    }
  }
}
```