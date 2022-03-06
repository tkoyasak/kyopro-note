# D - Sum of difference

No	: 186  
url	: https://atcoder.jp/contests/abc186/tasks/abc186_d  
tag	: [[累積和]]  #ABC #brown

### idea
- 入力をソートして$A_1 \le \ldots \le A_N$ とすると，$i<j$ に対して $|A_i-A_j|=A_j-A_i$ となる．
- 計算量は $\mathcal{O}(N \log N)$ ．

##### Method 1 (各 $j$ について引かれる数の和を考える)
- あらかじめ累積和を計算しておくことで各々 $\mathcal{O}(1)$ で求めることができる．
$$\sum_{i=1}^{N-1}\sum_{j=i+1}^{N} (A_j-A_i) = \sum_{j=2}^{N} (A_j*j-\sum_{i=1}^{j-1} A_i)$$

##### Method 2 (足された回数を考える)
- [アルゴリズム×数学 米田優峻  問題 5.7.3](https://github.com/E869120/math-algorithm-book/blob/main/editorial/chap5-7/chap5-7.pdf)
$$\sum_{i=1}^{N-1}\sum_{j=i+1}^{N} (A_j-A_i) = \sum_{i=1}^{N} A_i*(-N+2i-1)$$

### code
```cpp
// Method 1
int	main(void)
{
  int n; cin>>n;
  vl a(n); rep(i,n) cin>>a[i];
  ll ans=0,w=0;

  srt(a);
  rep(j,n) {
    ans+=a[j]*j-w;
    w+=a[j];
  }

  cout<<ans<<endl;
}
```

```cpp
// Method 2
int	main(void)
{
  int n; cin>>n;
  vl a(n); rep(i,n) cin>>a[i];
  ll ans=0;

  srt(a);
  rep(i,n) ans+=a[i]*(-n+2*i+1);
  cout<<ans<<endl;
}
```