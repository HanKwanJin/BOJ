//벽 부수고 이동하기
#include<bits/stdc++.h>
#define INF 98765432
using namespace std;

int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<string> v;
int dist[1001][1001][2];
queue<tuple<int,int,int>> q; //y,x,t  t -> 부쉈는가
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    memset(dist, INF, sizeof(dist));
    q.push({0,0,0});
    dist[0][0][0] = 1;
    while(!q.empty()){
        int y,x,t;
        tie(y,x,t) = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(v[ny][nx] == '0'){
                if(dist[ny][nx][t] > dist[y][x][t] + 1){
                    dist[ny][nx][t] = dist[y][x][t] + 1;
                    q.push({ny,nx,t});
                }
            }
            if(v[ny][nx] == '1' && t == 0){
                if(dist[ny][nx][1] > dist[y][x][0] + 1){
                    dist[ny][nx][1] = dist[y][x][0] + 1;
                    q.push({ny,nx,1});
                }
            }
        }
    }
    int mx = INF;
    for(int i=0; i<=1; i++){
        mx = min(mx, dist[n-1][m-1][i]);
    }
    cout << (mx == INF ? -1: mx);
}