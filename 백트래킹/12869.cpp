#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<tuple>
using namespace std;
int n;
int scv[3], vst[64][64][64], dp[64][64][64];
int ret = 987654321;
struct A{
	int a,b,c;
};
queue<A> q;
int damage[6][3] ={
	{9,3,1},
	{9,1,3},
	{3,1,9},
	{3,9,1},
	{1,3,9},
	{1,9,3}
};

int solve(int a, int b, int c){
	q.push({a,b,c});
	while(!q.empty()){
		int aa = q.front().a;
		int bb = q.front().b;
		int cc = q.front().c;
		q.pop();
		if(vst[0][0][0]) continue;
		for(int i=0; i<6; i++){
			int na = max(0, aa - damage[i][0]);
			int nb = max(0, bb - damage[i][1]);
			int nc = max(0, cc - damage[i][2]);
			if(vst[na][nb][nc]) continue;
			vst[na][nb][nc] = vst[aa][bb][cc] + 1;
			q.push({na,nb,nc});
		}
	}
	return vst[0][0][0];
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> scv[i];
	}
	cout << solve(scv[0], scv[1], scv[2]);
	return 0;
}
