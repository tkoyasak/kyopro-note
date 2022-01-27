#ifndef TEMPLATE_TKOYASAK

#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
using namespace std;

#define endl '\n'
#define ft first
#define sd second
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
#define rep1(n) for (int i=0;i<(n);++i)
#define rep2(i,n) for (int i=0;i<(n);++i)
#define rep3(i,m,n) for (int i=(m);i<(n);++i)
#define rep4(i,m,n,d) for (int i=(m);i<(n);i+=(d))
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define per1(n) for (int i=(n)-1;i>=0;--i)
#define per2(i,n) for (int i=(n)-1;i>=0;--i)
#define per3(i,m,n) for (int i=(m)-1;i>=n;--i)
#define per4(i,m,n,d) for (int i=(m)-1;i>=n;i-=(d))
#define per(...) overload4(__VA_ARGS__,per4,per3,per2,per1)(__VA_ARGS__)
#define fore(i,a) for(auto &i:(a))

template<class T> inline bool chmin(T& a, T b) {if(a>b){a=b;return(true);}return(false);}
template<class T> inline bool chmax(T& a, T b) {if(a<b){a=b;return(true);}return(false);}

using ll=long long; using ull=unsigned long long;
using vc=vector<char>; using vvc=vector<vc>; using vvvc=vector<vvc>;
using vi=vector<int>; using vvi=vector<vi>; using vvvi=vector<vvi>;
using vl=vector<ll>; using vvl=vector<vl>; using vvvl=vector<vvl>;
using vd=vector<double>; using vvd=vector<vd>; using vvvd=vector<vvd>;
using vb=vector<bool>; using vvb=vector<vb>; using vvvb=vector<vvb>;
using vs=vector<string>; using vvs=vector<vs>; using vvvs=vector<vvs>;
using pii=pair<int,int>; using pll=pair<ll,ll>; using pil=pair<int,ll>; using pli=pair<ll,int>; using pdd=pair<double,double>;
using vpii=vector<pii>; using vpll=vector<pll>; using vpil=vector<pil>; using vpli=vector<pli>; using vpdd=vector<pdd>;

#endif

const int dx4[4]={1,0,-1,0};
const int dy4[4]={0,1,0,-1};
const int dx8[8]={1,1,0,-1,-1,-1,0,1};
const int dy8[8]={0,1,1,1,0,-1,-1,-1};
const int inf=1e9+10;
// const int mod=1e9+7;
const int mod=998244353;
const long long INF=1e18;
const long double EPS=1e-10;


int	main(void)
{
  /* ---------- ---------- ---------- */
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  /* ---------- ---------- ---------- */


}
