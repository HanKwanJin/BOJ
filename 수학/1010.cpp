#include<iostream>
using namespace std;
int dp[31][31];
int t;
int n,m;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		dp[0][0] = 1;
		for(int i=1; i<=m; i++){
			for(int j=0; j<=m; j++){
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			}
		}
		cout << dp[m][n] << '\n';
	}
	return 0;
}
