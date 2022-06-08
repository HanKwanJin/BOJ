#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int board[102][102];
bool vst[102][102];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n;
void dfs(int y, int x, int h){
	vst[y][x] = 1;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if(board[ny][nx] >= h && !vst[ny][nx]){
			dfs(ny,nx, h);
		}
	}
	return;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}
	int area = 0;
	for(int h = 1; h <= 100; h++){
		int cnt = 0;
		memset(vst, 0, sizeof(vst));
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(board[i][j] >= h && !vst[i][j]){
					dfs(i,j, h);
					cnt++;
				}
			}
		}
		area = max(area, cnt);
	}
	cout << area;	
	return 0;
}
