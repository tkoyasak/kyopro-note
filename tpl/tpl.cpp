#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

// #include <atcoder/all>
// #include <atcoder/dsu>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/modint>
// using namespace atcoder;

const int inf=1e9+10;
const long long INF=1e18;
// const int mod=998244353;
// const int mod=1e9+7;

#ifndef tkoyasak_template

const int dx4[4]={1,0,-1,0};
const int dy4[4]={0,1,0,-1};
const int dx8[8]={1,1,0,-1,-1,-1,0,1};
const int dy8[8]={0,1,1,1,0,-1,-1,-1};

#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define bit(n) (1LL<<(n))
#define pcnt(n) __builtin_popcount(n)
#define all(obj) (obj).begin(),(obj).end()
#define rall(obj) (obj).rbegin(),(obj).rend()
#define sz(obj) (int)(obj).size()
#define srt(obj) sort(all(obj))
#define rsrt(obj) sort(rall(obj))
#define rev(obj) reverse(all(obj))
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define overload4(o1,o2,o3,o4,name,...) name
#define rep1(n) for (int rn4wqu22=0;rn4wqu22<(n);++rn4wqu22)
#define rep2(i,n) for (int i=0;i<(n);++i)
#define rep3(i,m,n) for (int i=(m);i<(n);++i)
#define rep4(i,m,n,d) for (int i=(m);i<(n);i+=(d))
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define per1(n) for (int rn4wqu22=(n)-1;rn4wqu22>=0;--rn4wqu22)
#define per2(i,n) for (int i=(n)-1;i>=0;--i)
#define per3(i,m,n) for (int i=(m)-1;i>=n;--i)
#define per4(i,m,n,d) for (int i=(m)-1;i>=n;i-=(d))
#define per(...) overload4(__VA_ARGS__,per4,per3,per2,per1)(__VA_ARGS__)
#define fore(i,a) for(auto &i:(a))

template<class T> inline bool chmin(T& a, T b) {if(a>b){a=b;return(true);}return(false);}
template<class T> inline bool chmax(T& a, T b) {if(a<b){a=b;return(true);}return(false);}
long long modpow(long long x,long long n,long long m) {if(m==1)return(0);long long val=1;while(n){if(n&1){val=(val*x)%m;}x=(x*x)%m;n>>=1;}return(val);}
long long modinv(long long x,long long m) {return(modpow(x,m-2,m));}


#ifndef MODINT
 #define mint int
#endif
using ll=long long; using ull=unsigned long long;
using vc=vector<char>; using vvc=vector<vc>; using vvvc=vector<vvc>;
using vi=vector<int>; using vvi=vector<vi>; using vvvi=vector<vvi>;
using vl=vector<ll>; using vvl=vector<vl>; using vvvl=vector<vvl>;
using vm=vector<mint>; using vvm=vector<vm>; using vvvm=vector<vvm>;
using vd=vector<double>; using vvd=vector<vd>; using vvvd=vector<vvd>;
using vb=vector<bool>; using vvb=vector<vb>; using vvvb=vector<vvb>;
using vs=vector<string>; using vvs=vector<vs>; using vvvs=vector<vvs>;
using pii=pair<int,int>; using pll=pair<ll,ll>; using pil=pair<int,ll>; using pli=pair<ll,int>;
using vpii=vector<pii>; using vpll=vector<pll>; using vpil=vector<pil>; using vpli=vector<pli>;
using pdd=pair<double,double>; using vpdd=vector<pdd>;

#endif

int	main(void)
{
  /* ---------- ---------- ---------- */
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  /* ---------- ---------- ---------- */

  
}
