#include<iostream>
using namespace std;
const int d = 10007;
int dp[1001][1001];
int n,k;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++){ //n
		for(int j=0; j<=n; j++){ //k
			if(i == j || j == 0){
				dp[i][j] = 1;
			}else{
				dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % d;
			}
		}
	}
	cout << dp[n][k];
	return 0;
}
