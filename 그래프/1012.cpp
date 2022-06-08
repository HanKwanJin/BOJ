#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
#define Y first
#define X second
using namespace std;

int t;
int n,m,k;
int board[55][55];
bool vst[55][55];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> m >> n >> k;
		memset(board, 0, sizeof(board));
		memset(vst, 0, sizeof(vst));
		for(int i=0; i<k; i++){
			int x,y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		int cnt = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(board[i][j] == 0 || vst[i][j]) continue;
				vst[i][j] = 1;
				cnt++;
				queue<pair<int,int>> q;
				q.push({i,j});
				while(!q.empty()){
					auto cur = q.front(); q.pop();
					for(int dir=0; dir<4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || ny < 0 || nx >= m || ny >= n || board[ny][nx] == 0) continue;
						if(vst[ny][nx]) continue;
						vst[ny][nx] = 1;
						q.push({ny,nx});
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
