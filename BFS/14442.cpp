//벽 부수고 이동하기 2
#include<bits/stdc++.h>
#define INF 98765432
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int dist[1001][1001][11];
vector<string> v;
int n,m,k;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    //맵
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    memset(dist, INF, sizeof(dist));
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    dist[0][0][0] = 1;
    while(!q.empty()){
        int cy,cx,t;
        tie(cy,cx,t) = q.front(); q.pop();
        for(int dir =0; dir<4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || ny <0 || nx >=m || ny >= n) continue;
            if(v[ny][nx] == '0'){
                if(dist[ny][nx][t] > dist[cy][cx][t] + 1){
                    dist[ny][nx][t] = dist[cy][cx][t] +1;
                    q.push({ny,nx,t});
                }
            }else if(v[ny][nx] == '1' && t < k){
                if(dist[ny][nx][t+1] > dist[cy][cx][t] + 1){
                    dist[ny][nx][t+1] = dist[cy][cx][t] + 1;
                    q.push({ny,nx,t+1});
                }
            }
        }
    }
    int mn = INF;
    
    for(int i=0; i<=k; i++){
        mn = min(mn, dist[n-1][m-1][i]);
    }
    cout << (mn == INF ? -1: mn);
    
}