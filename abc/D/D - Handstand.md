# D - Handstand

No	: 124  
url	: https://atcoder.jp/contests/abc124/tasks/abc124_d  
tag	: [[尺取り法]]  #ABC #green

### idea

### code
```cpp
vpii	run_length_encoding(string s) {
  int n=s.length(),cnt=1,pre=s[0];
  vpii res;

  reps(i,1,n) {
    if(pre!=s[i]) {
      res.emplace_back(pre,cnt);
      pre=s[i];
      cnt=1;
    }
    else cnt++;
  }
  res.emplace_back(pre,cnt);

  return res;
}

int	main(void)
{
  int n,k; cin>>n>>k;
  string s; cin>>s;
  vpii blocks=run_length_encoding(s);
  int ans=0,l=0,len=0,stand=0;

  rep(r,blocks.size()) {
    len+=blocks[r].second;
    if(blocks[r].first=='0') stand++;
    while(k<stand) {
      len-=blocks[l].second;
      if(blocks[l].first=='0') stand--;
      l++;
    }
    chmax(ans,len);
  }

  cout<<ans<<endl;
}
```