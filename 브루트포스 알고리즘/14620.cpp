#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 987654321;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int m[11][11];
bool vst[11][11];
int n,ret = INF;

int cost(int y, int x){
	int a = m[y][x];
	for(int dir =0; dir<4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		a += m[ny][nx];
	}
	return a;
}

void go(int y, int x, int cnt, int sum){
	if(cnt == 3){
		ret = min(ret, sum);
		return;
	}
	for(int i=1; i<n-1; i++){
		for(int j=1; j<n-1; j++){
			if(vst[i][j]) continue;
			bool flag = true;
			for(int dir=0; dir<4; dir++){
				int nx = j + dx[dir];
				int ny = i + dy[dir];
				if(nx < 0 || ny < 0 || nx >= n || ny >= n) flag = false;
				if(vst[ny][nx]) flag = false;
			}
			if(!flag) continue;
			vst[i][j] = 1;
			for(int dir =0; dir<4; dir++){
				int nx = j + dx[dir];
				int ny = i + dy[dir];
				vst[ny][nx] = 1;
			}
			go(i,j, cnt+1, sum + cost(i,j));
			vst[i][j] = 0;
			for(int dir =0; dir<4; dir++){
				int nx = j + dx[dir];
				int ny = i + dy[dir];
				vst[ny][nx] = 0;
			}
		}
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> m[i][j];
		}
	}
	go(1,1,0,0);
	cout << ret;
	return 0;
}
