#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
#define X second
#define Y first
using namespace std;
vector<string> board;
vector<pair<int,int>> list;
queue<pair<int,int>> q;
int dist[54][54];
int n,m;
int ret = -987654321;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		board.push_back(s);
		for(int j=0; j<m; j++){
			if(board[i][j] == 'L') list.push_back({i,j});
		}
	}
	for(int i=0; i<list.size(); i++){
		memset(dist, -1, sizeof(dist));
		auto cur = list[i];
		dist[cur.Y][cur.X] = 0;
		q.push({cur.Y, cur.X});
		while(!q.empty()){
			auto d = q.front(); q.pop();
			for(int dir = 0; dir<4; dir++){
				int nx = d.X + dx[dir];
				int ny = d.Y + dy[dir];
				if(nx < 0 || ny < 0 || nx >= m || ny >= n || dist[ny][nx] >= 0) continue;
				if(board[ny][nx] == 'W') continue;
				dist[ny][nx] = dist[d.Y][d.X] + 1;
				ret = max(ret, dist[ny][nx]);
				q.push({ny,nx});
			}
		}
	}
	cout << ret;
	return 0;
}
