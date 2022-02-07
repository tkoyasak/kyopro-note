# C - Colorful Candies

No	: 210  
url	: https://atcoder.jp/contests/abc210/tasks/abc210_c  
tag	: [[尺取り法]]  #ABC #gray

### idea
- 区間 $[i,i+k-1]$ の中で，種類数をカウントしていく．
- 種類数を計算するために以下を用意する．
	- $\text{kinds}$ : 現在の区間の種類数
	- $\text{cnt}$ : 現在の区間に各バリューが何個含まれているか
- 区間が更新されたら，$\text{cnt}[l]$ (左端)をデクリメント，$\text{cnt}[r]$ (右端)をインクリメントする．

### code
```cpp
int	main(void)
{
  int n,k; cin>>n>>k;
  vi c(n); rep(i,n) cin>>c[i];
  map<int,int> cnt;
  int ans=0,kinds=0;

  rep(i,n) {
    if(cnt[c[i]]==0) ++kinds;
    cnt[c[i]]++;
    if(i>=k) {
      cnt[c[i-k]]--;
      if(cnt[c[i-k]]==0) --kinds;
    }
    chmax(ans,kinds);
  }

  cout<<ans<<endl;
}
```