#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<utility>
#define Y first
#define X second
using namespace std;
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
string s;
vector<string> lake;
queue<pair<int,int>> w;
vector<pair<int,int>> v;
queue<pair<int,int>> q;
bool vst[1501][1501];
bool lvst[1501][1501];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> s;
		lake.push_back(s);
		for(int j=0; j<m; j++){
			if(s[j] == 'L'){
				w.push({i,j});
				v.push_back({i,j});
				lake[i][j] = '.';
			}else if(s[j] == '.') w.push({i,j});
		}
	}
	int cnt = 0;
	while(1){ //백조 끼리 만나면 flag = true 
		queue<pair<int,int>> nq;
		q.push(v[0]);
		vst[v[0].Y][v[0].X] = 1;
		while(!q.empty()){
			auto cur = q.front(); q.pop();
			for(int dir = 0; dir<4; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if(vst[ny][nx]) continue;
				if(ny == v[1].Y && nx == v[1].X){
					cout << cnt;
					return 0;
				}
				if(lake[ny][nx] == '.'){
					q.push({ny,nx});
				}else if(lake[ny][nx] == 'X'){
					nq.push({ny,nx});
				}
				vst[ny][nx] = 1;
			}
		}
		q = nq;
		cnt++;// 못 찾으면 녹이고 하루를 넘김 
		int ws = w.size();
		while(ws--){
			auto cur = w.front(); w.pop();
			for(int dir =0; dir<4; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if(lake[ny][nx] == 'X'){
					w.push({ny,nx});
					lake[ny][nx] = '.';
				}
			}
		}
	}
	return 0;
}
