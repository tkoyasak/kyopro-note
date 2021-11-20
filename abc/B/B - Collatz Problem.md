# B - Collatz Problem

No	: 116  
url	: https://atcoder.jp/contests/abc116/tasks/abc116_b  
tag	: [[整数判定]]  #ABC #gray

### idea
- ある数が以前に出ていたかを判定するにはsetを使うといい．
- 以前に出たことある数が出たら，その番号を答える．

### code
```cpp
int	mian(void)
{
  ll s;
  cin>>s;
  set<ll> done;
  done.insert(s);
  ll cur=s;

  reps(i,2,1000001) {
    ll next;
    if(cur%2==0) next=cur/2;
    else next=3*cur+1;
  
    if(done.count(next)) {
      cout<<i<<endl;
      return 0;
    }
  
    done.insert(cur);
    cur=next;
  }
}
```