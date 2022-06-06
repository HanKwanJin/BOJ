#include<iostream>
typedef long long ll;
using namespace std;
ll a,b,c;
ll func(ll a, ll b){
	if(b == 1) return a % c;
	ll ret = func(a, b/2);
	ret = (ret * ret) % c;
	if(b & 1) return ret * a % c;
	return ret;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	cout << func(a,b);
	return 0;
}
