#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ret;
ll ret2;
ll n,m;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i=5; n/i >= 1; i*=5){
		ret += n / i;
	}
	for(ll i=5; m/i >= 1; i*=5){
		ret -= m / i;
	}
	for(ll i=5; (n-m)/i >= 1; i*=5){
		ret -= (n-m) / i;
	}
	
	for(ll i=2; n/i >= 1; i*=2){
		ret2 += n / i;
	}
	for(ll i=2; m/i >= 1; i*=2){
		ret2 -= m / i;
	}
	for(ll i=2; (n-m)/i >= 1; i*=2){
		ret2 -= (n-m) / i;
	}
	cout << min(ret, ret2);
	return 0;
}
