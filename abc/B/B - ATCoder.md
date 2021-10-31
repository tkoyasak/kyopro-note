# B - ATCoder

No	: 122  
url	: https://atcoder.jp/contests/abc122/tasks/abc122_b  
tag	: [[文字列操作]]  #ABC #gray

### idea
- `sub="ACGT"` と置いてその中に文字があるかを判定する．

### code
```cpp
int	main(void)
{
	string s;
	cin>>s;
	string sub="ACGT";
	ll ans=0;
	rep(i,s.size()) {
		ll len=0;
		rep(j,s.size()-i+1) {
			if(sub.find(s[i+j])) len++;
			else break;
		}
		chmax(ans,len);
	}
	cout<<ans<<endl;
}
```