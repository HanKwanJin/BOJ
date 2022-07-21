#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#define X second
#define Y first
using namespace std;

int n,m,cnt;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool a[26];
int dist[21][21];
string s;
vector<string> v;

bool chk(int y, int x){
	for(int dir=0; dir<4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if(a[(int)v[ny][nx] - 'A']) continue;
		return true;
	}
	return false;
}
void func(int y, int x){
	if(!chk(y,x)){
		cnt = max(cnt, dist[y][x]);
		return;
	}
	for(int dir=0; dir<4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if(!a[(int)v[ny][nx] - 'A']){
			a[(int)v[ny][nx] - 'A'] = 1;
			dist[ny][nx] = dist[y][x] + 1;
			func(ny,nx);
			a[(int)v[ny][nx] - 'A'] = 0;
			dist[ny][nx] = 0;
		}
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> s;
		v.push_back(s);
	}
	a[(int)v[0][0] - 'A'] = 1;
	dist[0][0] = 1;
	func(0,0);
	cout << cnt;
	return 0;
}
