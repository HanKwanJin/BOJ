#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
#include<string>
#define Y first
#define X second
using namespace std;
queue<pair<int,int>> q;
string board[104];
int dist[104][104];
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	memset(dist, -1, sizeof(dist));
	for(int i=0; i<n; i++){
		cin >> board[i];
	}
	q.push({0,0});
	dist[0][0] = 1;
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || ny >= n || nx >= m || board[ny][nx] == '0') continue;
			if(dist[ny][nx] != -1) continue;
			q.push({ny,nx});
			dist[ny][nx] = dist[cur.Y][cur.X] + 1;
		}
	}
	cout << dist[n-1][m-1];
	return 0;
}
