# C - Triangular Relationship

No	: 102  
url	: https://atcoder.jp/contests/abc108/tasks/arc102_a  
tag	: [[剰余]]  #ABC #green

### idea
- 条件「 $K \mid a+b$ 」かつ「 $K \mid b+c$ 」かつ「 $K \mid c+a$ 」より次が成り立つ．
$$a \equiv b \equiv c \pmod K$$
- したがって，条件を満たすのは次の２通り．
	1. 「 $a \equiv b \equiv c \equiv 0 \pmod K$ 」
	2. 「 $a \equiv b \equiv c \equiv K/2 \pmod K$ 」

### code
```cpp
int	main(void)
{
  int n,k; cin>>n>>k;
  int u=0,v=0;
  ll ans=0;

  for(int i=k;i<=n;i+=k) u++;
  ans+=1LL*u*u*u;
  if(k%2==0) for(int i=k/2;i<=n;i+=k) v++;
  ans+=1LL*v*v*v;

  cout<<ans<<endl;
}
```