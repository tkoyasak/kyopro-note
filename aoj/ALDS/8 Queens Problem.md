# 8 Queens Problem

No	: ALDS1 - 13A  
url	: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_13_A  
tag	: [[深さ優先探索]]  #AOJ #black

### idea
- 行，列にかぶりのないようにクイーンを配置する場合の数は $8!$ 通りある．
- より高速化するには，行方向，列方向，右斜め方向，左斜め方向に配置可能かどうかを判定するフラグを用意しておく．

### code
```cpp
bool col[8],row[8],rdg[15],ldg[15];
vs board;

void dfs(int r) {
  if(r==8) {
    rep(i,8) cout<<board[i]<<endl;
    exit(0);
  }
  if(row[r])  return dfs(r+1);
  rep(c,8) {
    if(col[c]||rdg[r+c]||ldg[r-c+7]) continue;
    board[r][c]='Q';
    col[c]=row[r]=rdg[r+c]=ldg[r-c+7]=true;
    dfs(r+1);
    board[r][c]='.';
    col[c]=row[r]=rdg[r+c]=ldg[r-c+7]=false;
  }
}

int	main(void)
{
  board.assign(8,string(8,'.'));
  int k; cin>>k;
  rep(i,k) {
    int r,c; cin>>r>>c;
    board[r][c]='Q';
    row[r]=col[c]=rdg[r+c]=ldg[r-c+7]=true;
  }

  dfs(0);
}
```