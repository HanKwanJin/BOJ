#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
int coin[104];
int dp[10004];

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> coin[i];
	}
	dp[0] = 1;
	for(int i=1; i<=n; i++){
		if(coin[i] >= 10001) continue;
		for(int j=coin[i]; j<=k; j++){
			dp[j] += dp[j-coin[i]];
		}
	}
	cout << dp[k];
	return 0;
}
