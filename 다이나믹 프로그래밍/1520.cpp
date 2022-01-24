//내리막 길
#include<bits/stdc++.h>
#define MAX 501
using namespace std;
int nn,mm;
int dp[MAX][MAX];
int board[MAX][MAX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int yy,int xx){
    if( yy == nn-1 && xx == mm-1) return 1;
    if(dp[yy][xx] != -1) return dp[yy][xx];
    dp[yy][xx] = 0;
    for(int dir=0; dir<4; dir++){
        int nx = xx + dx[dir];
        int ny = yy + dy[dir];
        if( nx < 0 || ny < 0 || nx >= mm || ny >= nn) continue;
        if( board[ny][nx] < board[yy][xx]){
           dp[yy][xx] += dfs(ny,nx);
        }
    }
    return dp[yy][xx];
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> nn >> mm;
    
    for(int i= 0; i<nn; i++){
        for(int j=0; j<mm; j++){
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }
    int ret = dfs(0,0);
    cout << ret <<'\n';
    return 0;
    
}