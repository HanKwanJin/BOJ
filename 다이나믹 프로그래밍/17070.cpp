#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n;
int y, x;
int dp[24][24][3];
int m[24][24];

bool chk(int y, int x, int dir){
	if(dir == 0 || dir == 1){
		if(!m[y][x]) return true;
	}
	if(dir == 2){
		if(m[y-1][x] == 0 && m[y][x] == 0 && m[y][x-1] == 0) return true;
	}
	return false;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> m[i][j];
		}
	}
	
	dp[1][2][0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			//dir 0
			if(chk(i,j+1,0)) dp[i][j+1][0] += dp[i][j][0];
			if(chk(i+1,j+1,2)) dp[i+1][j+1][2] += dp[i][j][0];
			//dir 1
			if(chk(i+1,j,1)) dp[i+1][j][1] += dp[i][j][1];
			if(chk(i+1,j+1,2)) dp[i+1][j+1][2] += dp[i][j][1];
			//dir 2
			if(chk(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][2];
			if(chk(i+1,j,1)) dp[i+1][j][1] += dp[i][j][2];
			if(chk(i+1,j+1,2)) dp[i+1][j+1][2] += dp[i][j][2];
		}
	}
	
	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	return 0;
}
