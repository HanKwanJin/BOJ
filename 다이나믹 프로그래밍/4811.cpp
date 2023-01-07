#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll n;
ll dp[64][64];

ll func(ll one, ll half){
	if(!one && !half) return 1;
	if(dp[one][half]) return dp[one][half];
	if(one > 0){
		dp[one][half] += func(one-1, half+1);
	}
	if(half > 0){
		dp[one][half] += func(one, half-1);
	}
	return dp[one][half];
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while(1){
		cin >> n;
		if(n == 0) break;
		memset(dp, 0, sizeof(dp));
		cout << func(n-1, 1) << '\n';
	}
	return 0;
}
