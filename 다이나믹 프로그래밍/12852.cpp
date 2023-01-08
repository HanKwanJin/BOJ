#include<algorithm>
#include<iostream>
using namespace std;
int n;
int dp[1000004];
void func(int k){
	if(k == 0) return;
	cout << k << ' ';
	if(k % 3 == 0 && dp[k] == dp[k/3]+1) func(k/3);
	else if(k % 2 == 0 && dp[k] == dp[k/2]+1) func(k/2);
	else func(k-1);
	return;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	fill(dp, dp + 1000004, 1e9);
	dp[1] = 0;
	for(int i=1; i<= n; i++){
		if(i % 3 == 0){
			dp[i] = min(dp[i/3] + 1, dp[i]);
		}
		if(i % 2 == 0){
			dp[i] = min(dp[i/2] + 1, dp[i]);
		}
		dp[i] = min(dp[i-1] + 1, dp[i]);
	}
	cout << dp[n] << '\n';
	func(n);
	return 0;
}
