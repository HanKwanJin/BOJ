#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,m;
int mx;
int dp[10004];
vector<int> v[10004];
bool vst[10004];
int dfs(int k){
	vst[k] = 1;
	int ret = 1;
	for(auto e: v[k]){
		if(vst[e]) continue;
		ret += dfs(e);
	}
	return ret;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		v[b].push_back(a); //b를 해킹했을 때 해킹 할 수 있는 컴퓨터들 
	}
	for(int i=1; i<=n; i++){
		memset(vst, false, sizeof(vst));
		dp[i] = dfs(i);
		mx = max(mx, dp[i]);
	}
	for(int i=1; i<= n; i++) if(mx == dp[i]) cout << i << ' ';
	return 0;
}
