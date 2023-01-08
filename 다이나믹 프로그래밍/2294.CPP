#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,k;
ll coin[104];
ll dp[10004];
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	
	for(int i=1; i<=10000; i++) dp[i] = 1e9;
	for(int i=1; i<=n; i++){
		cin >> coin[i];
		if(coin[i] > 10000) continue;
		dp[coin[i]] = 1;
	}
	// 0 -> 0 dp[i] = j i원 까지 j개 사용 
	for(int i=1; i<=n; i++){
		if(coin[i] > 10000) continue;
		for(int j=coin[i]; j<=k; j++){
			dp[j] = min(dp[j],dp[j-coin[i]] + 1);
		}
	} 
	cout << (dp[k] == 1e9 ? -1 : dp[k]);
	return 0;
}
