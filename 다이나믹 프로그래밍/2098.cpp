#include<iostream>
#include<cstring>
#include<algorithm>
#define MX 16
using namespace std;
int n;
const int INF = 987654321;
//dp[here][지금까지 방문한 곳들] 
int dp[MX][1 << MX], dist[MX][MX];

int tsp(int here, int vst){
	if(vst == (1 << n) - 1){
		//다 방문하고 0번 도시로 다시 도달 
		return dist[here][0] ? dist[here][0] : INF;
	}
	
	if(dp[here][vst] != -1) return dp[here][vst];
	dp[here][vst] = INF;
	
	for(int i=0; i<n; i++){
		if(vst & (1 << i)) continue;
		if(dist[here][i] == 0) continue; 
		dp[here][vst] = min(dp[here][vst], tsp(i, vst | (1 << i)) + dist[here][i]); 
	}
	return dp[here][vst];
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> dist[i][j];
		}
	} 
	
	memset(dp, -1, sizeof(dp));
	//어디서 출발하든 상관없다 tsp 알고리즘의 핵심
	//0번도시에서 출발, vst = 1 
	cout << tsp(0, 1) << '\n';
	return 0;
}