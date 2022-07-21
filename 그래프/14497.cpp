#include<iostream>
#include<utility>
#include<string>
#include<queue>
#include<vector>
#include<cstring> 
#define X second
#define Y first
using namespace std;
vector<string> board;
queue<pair<int,int>> q;
string s;
int n,m,a,b,c,d, cnt;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int vst[304][304];
void fastio(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main(void){
	fastio();
	cin >> n >> m;
	cin >> a >> b >> c >> d;
	a--, b--, c--, d--;
	for(int i=0; i<n; i++){
		cin >> s;
		board.push_back(s);
	}
	q.push({a,b});
	vst[a][b] = 1;
	while(board[c][d] != '0'){
		cnt++;
		queue<pair<int,int>> tmp;
		while(!q.empty()){
			auto cur = q.front(); q.pop();
			for(int dir=0; dir<4; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || ny < 0 || nx >= m || ny >= n ) continue;
				if(vst[ny][nx]) continue;
				if(board[ny][nx] != '0'){
					board[ny][nx] = '0';
					tmp.push({ny,nx});
				}else{
					q.push({ny,nx});
				}
				vst[ny][nx] = cnt;
			}
		}
		q = tmp;
	}
	
	cout << vst[c][d];
	return 0;
}
