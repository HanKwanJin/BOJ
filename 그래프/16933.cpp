//벽 부수고 이동하기 3
#include<bits/stdc++.h>
#define INF 98765432
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int dist[1001][1001][11][2];

int n,m,k;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    //맵
    vector<string> v(n);
    for(string & i: v) cin >> i;
    
    queue<tuple<int,int,int,int>> q;
    q.push({0,0,0,0});
    dist[0][0][0][0] = 1;
    while(!q.empty()){
        int cy,cx,t,day;
        tie(cy,cx,t,day) = q.front(); q.pop();
        for(int dir =0; dir<4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || ny <0 || nx >=m || ny >= n) continue;
            if(v[ny][nx] == '0' && dist[ny][nx][t][1-day] == 0){
                dist[ny][nx][t][1-day] = dist[cy][cx][t][day] +1;
                q.push({ny,nx,t,1-day});
            }
            if(day == 0 && t < k && v[ny][nx] == '1' && dist[ny][nx][t+1][1-day] == 0){
                dist[ny][nx][t+1][1-day] = dist[cy][cx][t][day] +1;
                q.push({ny,nx,t+1,1-day});
            }
        }

        if(dist[cy][cx][t][1-day] == 0){
            dist[cy][cx][t][1-day] = dist[cy][cx][t][day] + 1;
            q.push({cy,cx,t,1-day});
        }
    }
    int mn = -1;
    
    for(int i=0; i<=k; i++){
        for(int j=0; j<2; j++){
            if(dist[n-1][m-1][i][j] == 0) continue;
            if(mn == -1 || mn > dist[n-1][m-1][i][j]){
                mn = dist[n-1][m-1][i][j];
            }
        }
    }
    cout << mn;
    
}