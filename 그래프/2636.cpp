#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
#define X second
#define Y first
using namespace std;
int n,m;
int ret1, ret2;
int board[101][101];
bool vst[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<pair<int,int>> v;
void dfs(int y, int x){
	if(board[y][x] == 1){
		v.push_back({y,x});
		return;
	}
	for(int dir=0; dir<4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 0 || ny < 0 || nx >= m || ny >= n || vst[ny][nx]) continue;
		vst[ny][nx] = 1;
		dfs(ny, nx);
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}
	
	while(true){
		ret2 = 0;
		bool flag = false;
		memset(vst, false, sizeof(vst));
		dfs(0,0);
		ret1++;
		for(auto e : v) if(board[e.Y][e.X] == 1) ret2++;
		for(auto e : v) board[e.Y][e.X] = 0;
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(board[i][j] == 1){
					 flag = true;
					 break;
				}
			}
			if(flag) break;
		}
		if(!flag) break;
	}
	cout << ret1 << '\n' << ret2;
	return 0;
}
