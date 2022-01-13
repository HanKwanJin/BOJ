//토마토
#include<bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int n,m;
int board[1010][1010];
int day[1010][1010];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int>> q;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    memset(day,-1,sizeof(day));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                q.push({i,j});
                day[i][j] = 0;
            }else if(board[i][j] == -1){
                day[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir <4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(board[ny][nx] == -1 || day[ny][nx] != -1) continue;
            day[ny][nx] = day[cur.Y][cur.X] + 1;
            q.push({ny,nx});
        }
    }
    int mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(day[i][j] == -1){
                cout << -1;
                return 0;
            }
            mx = max(mx, day[i][j]);
        }
    }
    cout << mx;
    return 0;
}