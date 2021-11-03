# B - Minesweeper

No	: 075  
url	: https://atcoder.jp/contests/abc075/tasks/abc075_b  
tag	: [[全探索]]  #ABC #gray

### idea
- 近傍の座標を探索する常套テク．
- 変数$dx=[-1,0,1],dy=[-1,0,1]$を用意すると，近傍の座標は$x+dx,y+dy$で表せる．

### code
```cpp
int main(void)
{
	ll h,w; cin>>h>>w;
	vs s(h); rep(i,h) cin>>s[i];

	rep(y,h) rep(x,w) if(s[y][x]=='.') {
		int cnt=0;
		reps(dx,-1,2) reps(dy,-1,2) {
			if(dx==0&&dy==0) continue;
			int xx=x+dx;
			int yy=y+dy;
			if(0<=xx&&xx<w && 0<=yy&&yy<h) {
				if(s[yy][xx]=='#') cnt++;
			}
		}
		s[y][x]=(char)(cnt+'0');
	}

	rep(i,h) cout<<s[i]<<endl;
}
```
