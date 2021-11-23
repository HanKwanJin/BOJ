#include<iostream>
#include<utility>
#include<cstring>
#include<queue>
#include<algorithm>

#define Y first
#define X second

using namespace std;


int dist[305][305];

int dx[8] = {-1,-2,-1,-2,1,2,1,2};
int dy[8] = {-2,-1,2,1,2,1,-2,-1};
int n,t;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        int curY, curX;
        int nextY, nextX;

        memset(dist,-1,sizeof(dist));
        cin >> n;

        cin >> curY >> curX;
        cin >> nextY >> nextX;
        
        dist[curY][curX] = 0;
        

        queue<pair<int,int>> q;
        q.push({curY, curX});

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir =0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny <0 || nx >= n || ny >= n) continue;
                if(dist[ny][nx] >= 0) continue;
                dist[ny][nx] = dist[cur.Y][cur.X] + 1;
                q.push({ny,nx});
            }
        }
        
        cout << dist[nextY][nextX] << '\n';

    }
}