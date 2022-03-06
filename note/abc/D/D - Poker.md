# D - Poker

No	: 193  
url	: https://atcoder.jp/contests/abc193/tasks/abc193_d  
tag	: [[確率]]  #ABC #green

### idea
- すべての配り方は $(9K-8)(9K-9)$．
- 高橋くんに $x$ 青木くんに $y$ 配る方法の数は，$C_i$ をまだ見えていない $i$ の枚数として，
	$$\begin{cases}
		C_xC_y & ( x \neq y ) \\
		C_x(C_x-1) & ( x = y )
	\end{cases}$$
- したがって，高橋くんの勝つ配り方の数は，高橋くんの勝つような $(x,y)$ の組についてこの総和を求めれば良い．


### code
```cpp
int	main(void)
{
  ll k; cin>>k;
  string s,t; cin>>s>>t;
  vll cnt(10,k);
  ll win=0;

  auto score=[](string s) {
    vll p(10);
    iota(all(p),0);
    fore(c,s) p[c-'0']*=10;
    return accumulate(all(p),0);
  };

  fore(c,s+t) if(c!='#') cnt[c-'0']--;
  reps(i,1,10) reps(j,1,10) {
    s[4]=i+'0'; t[4]=j+'0';
    if(score(s)>score(t)) win+=cnt[i]*(cnt[j]-(i==j));
  }

  printf("%.10f\n",(double)win/(9*k-8)/(9*k-9));
}
```