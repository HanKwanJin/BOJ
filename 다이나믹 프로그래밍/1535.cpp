#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int L[24], j[24];
int dp[24][104];
vector<pair<int,int>> v;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> L[i];
	}
	for(int i=1; i<=n; i++){
		cin >> j[i];
	}
	v.push_back({-1,-1});
	for(int i=1; i<=n; i++){
		v.push_back({L[i], j[i]});
	}
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=100; j++){
			if(j > v[i].first){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j - v[i].first] + v[i].second);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[n][100];
	return 0;
}
