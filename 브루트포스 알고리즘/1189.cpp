#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n,m,k,cnt,ret;
vector<string> v;
bool vst[5][5];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void go(int y, int x, int cnt){
	if(cnt > k) return;
	if(y == 0 && x == m-1){
		if(cnt == k) ret++;
		return;
	}
	for(int dir=0; dir<4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if(vst[ny][nx] || v[ny][nx] == 'T') continue;
		vst[ny][nx] = 1;
		go(ny, nx, cnt+1);
		vst[ny][nx] = 0;
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	vst[n-1][0] = 1;
	go(n-1,0,1);
	cout << ret; 
	return 0;
}
