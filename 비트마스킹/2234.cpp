#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
#include<utility>
#include<cstring>
#define X second
#define Y first
using namespace std;

int n, m;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int board[54][54], vst[54][54];
int comb[2504];
int cnt, mx, area;
int dfs(int y, int x, int id){
	if(vst[y][x]) return 0;
	vst[y][x] = id;
	int ret = 1;
	for(int dir=0; dir<4; dir++){
		if(!(board[y][x] & (1 << dir))){
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			ret += dfs(ny,nx,id);
		}
	}
	return ret;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	for(int i = 0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!vst[i][j]){
				cnt++;
				comb[cnt] = dfs(i,j, cnt);
				mx = max(mx, comb[cnt]);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i + 1 < n) {
				int a = vst[i+1][j];
				int b = vst[i][j];
				if(a != b){
					area = max(area, comb[a] + comb[b]);
				}
			}
			if(j + 1 < m) {
				int a = vst[i][j+1];
				int b = vst[i][j];
				if(a != b){
					area = max(area, comb[a] + comb[b]);
				}
			}
		}
	}
	cout << cnt << '\n' << mx << '\n' << area;
	return 0;
}
