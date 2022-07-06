#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#define X second
#define Y first
using namespace std;
int n,m;
int board[10][10];
int ori[10][10];
int ret;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool vst[10][10];
queue<pair<int,int>> q;

void input(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}
}

void bfs(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ori[i][j] = board[i][j];
			if(ori[i][j] == 2){
				q.push({i,j});
				vst[i][j] = 1;
			}
		}
	}
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int dir=0; dir<4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if(!vst[ny][nx] && ori[ny][nx] == 0){
				q.push({ny,nx});
				ori[ny][nx] = 2;
			}
		}
	}
	int k = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			k += (ori[i][j] == 0);
		}
	}
	ret = max(k, ret);
}

void wall(int cnt, int y, int x){
	if(cnt == 3){
		bfs();
		return;
	}
	for(int i=y; i<n; i++){
		for(int j=x; j<m; j++){
			if(board[i][j] == 0){
				board[i][j] = 1;
				wall(cnt+1, i,j);
				board[i][j] = 0;
			}
		}
		x = 0;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	input();
	wall(0,0,0);
	cout << ret;
	return 0;
}
