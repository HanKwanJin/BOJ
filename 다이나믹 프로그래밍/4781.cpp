#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
typedef long long ll;

ll n,m;
ll a,b;
double bb;
vector<pair<ll,ll>> v;
ll dp[10004];
bool cmp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first > b.first;
}
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while(1){
		cin >> n >> bb;
		m = bb * 100 + 0.5;
		if(n == 0){
			break;
		}
		v.clear();
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++){
			cin >> a >> bb;
			b = bb * 100 + 0.5;
			for(int j=b; j<=m; j++){
				dp[j] = max(dp[j], dp[j-b] + a);
			}
		}
		cout << dp[m] << '\n';
	}
	return 0;
}
