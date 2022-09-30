#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#include<cstring>
using namespace std;
int r,c,t;
int a[54][54];
int tmp[54][54];
int dy1[4] = {0,-1,0,1};
int dx1[4] = {1,0,-1,0};

int dy2[4] = {0,1,0,-1};
int dx2[4] = {1,0,-1,0};

vector<pair<int,int>> v1,v2;

void bfs(){
    memset(tmp, 0, sizeof(tmp));
    queue<pair<int,int>> q;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(a[i][j] != -1 && a[i][j]){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int spread = a[cur.first][cur.second] / 5;
        for(int dir=0; dir<4; dir++){
            int ny = cur.first + dy1[dir];
            int nx = cur.second + dx1[dir];
            if(nx < 0 || ny < 0 || nx >= c || ny >= r || a[ny][nx] == -1) continue;
            tmp[ny][nx] += spread;
            a[cur.first][cur.second] -= spread;
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            a[i][j] += tmp[i][j];
        }
    }
    return;
}

void go(vector<pair<int,int>> &v){
    for(int i=v.size()-1; i > 0; i--){
        a[v[i].first][v[i].second] = a[v[i-1].first][v[i-1].second]; 
    }
    a[v[0].first][v[0].second] = 0;
    return;
}

vector<pair<int,int>> solution(int cy, int cx, int dy[], int dx[]){
    vector<pair<int,int>> v;
    int dir = 0;
    int y = cy;
    int x = cx;
    while(1){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny == cy && nx == cx) break;
        if(ny < 0 || nx < 0 || ny >= r || nx >= c){
            dir++;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        if(ny == cy && nx == cx) break;
        y = ny;
        x = nx;
        v.push_back({ny,nx});
    }
    return v;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> r >> c >> t;
    bool flag = false;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
            if(a[i][j] == -1){
                if(!flag){ //공기청정기 위쪽 부분
                    v1 = solution(i,j,dy1,dx1);
                    flag = true;
                }else{ //공기청정기 아래쪽 부분
                    v2 = solution(i,j,dy2,dx2);
                }
            }
        }
    }
    while(t--){
        bfs();
        go(v1);
        go(v2);
    }
    int ret = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(a[i][j] != -1 && a[i][j]) ret += a[i][j];
        }
    }
    cout << ret << '\n';
    return 0;
}