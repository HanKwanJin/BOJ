#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define Y first
#define X second
using namespace std;
int n;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int m[504][504];
int dp[504][504];
int ret;

int func(int y, int x){
	if(dp[y][x] != 0) return dp[y][x];
	
	dp[y][x] = 1;
	for(int dir=0; dir<4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
		if(m[ny][nx] > m[y][x]){
			dp[y][x] = max(dp[y][x], func(ny,nx) + 1);
		}
	}
	return dp[y][x];
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> m[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ret = max(ret, func(i,j));
		}
	}
	cout << ret;
	return 0;
}
