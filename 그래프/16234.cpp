#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
#define X second
#define Y first
using namespace std;
int n,l,r;
int day;
int board[54][54];
bool vst[54][54];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> r;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}
	while(true){
		int sum = 0;
		bool flag = false; //열린 나라가 있으면 true
		memset(vst, false, sizeof(vst));
		queue<pair<int,int>> q;
		vector<pair<int,int>> v; //이동 후 바꿀 나라들
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(vst[i][j]) continue;
				vst[i][j] = 1;
				q.push({i,j});
				v.push_back({i,j});
				sum = board[i][j];
				while(!q.empty()){
					auto cur = q.front(); q.pop();
					for(int dir=0; dir<4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						int tmp = abs(board[cur.Y][cur.X] - board[ny][nx]);
						if(nx < 0 || ny < 0 || nx >= n || ny >= n || vst[ny][nx]) continue;
						if(tmp >= l && tmp <= r){
							vst[ny][nx] = 1;
							q.push({ny,nx});
							v.push_back({ny,nx});
							sum += board[ny][nx];
							flag = true;
						}
					}
				}
				for(auto e: v){
					board[e.Y][e.X] = sum / v.size();
				}
				v.clear();
			}
		}
		if(!flag) break;
		day++;
	}
	cout << day;
	return 0;
}
