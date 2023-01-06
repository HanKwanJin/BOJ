#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n,m;
string s;
char a[54][54];
bool vst[54][54];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0}; //down up right left 
int dp[54][54];
int dfs(int y, int x){
	if(x < 0 || y < 0 || x >= m || y >= n || a[y][x] == 'H') return 0;
	if(vst[y][x]){
		cout << -1;
		exit(0);
	}
	
	if(dp[y][x]) return dp[y][x];
	
	vst[y][x] = 1;
	int value = (int)a[y][x] - '0';
	for(int dir=0; dir<4; dir++){
		int nx = x + value * dx[dir];
		int ny = y + value * dy[dir];
		dp[y][x] = max(dp[y][x], dfs(ny,nx) + 1);
	}	
	vst[y][x] = 0;
	return dp[y][x];
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	//init
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<s.size(); j++){
			a[i][j] = s[j];
		}
	}
	cout << dfs(0,0);
	return 0;
}
