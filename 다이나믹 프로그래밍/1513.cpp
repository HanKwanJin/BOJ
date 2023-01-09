#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define MOD 1000007
using namespace std;

int n,m,c;
int d[54][54];
int dp[54][54][54][54]; //y, x, cnt, prev

int func(int y, int x, int cnt, int prev){
	if(y > n || x > m) return 0;
	if(y == n && x == m){
		if(cnt == 0 && d[y][x] == 0) return 1;
		if(cnt == 1 && d[y][x] > prev) return 1;
		return 0;
	}
	int &ret = dp[y][x][cnt][prev];
	if(ret != -1) return ret;
	ret = 0;
	if(d[y][x] == 0){
		ret = (func(y+1,x,cnt,prev) +  func(y, x+1, cnt, prev)) % MOD;
	}else if(d[y][x] > prev){
		ret = (func(y+1,x,cnt-1, d[y][x]) + func(y, x+1, cnt-1, d[y][x])) % MOD;
	}
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> c;
	for(int i=1; i<=c; i++){
		int x,y;
		cin >> y >> x;
		d[y][x] = i; //oraksil 
	}
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<=c; i++){
		cout << func(1,1,i,0) << " ";
	}
	return 0;
}
