#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,k;
ll d[300004];

bool chk(ll mid){
	ll a = 0;
	for(int i=0; i<m; i++){
		a += d[i] / mid;
		if(d[i] % mid) a++;
	}
	return n >= a;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ll st = 1, en = 0, mid;
	ll ret = 1e18;
	for(int i=0; i <m; i++){
		cin >> d[i];
		en = max(en, d[i]);
	}
	while(st <= en){
		mid = (st + en) /2;
		if(chk(mid)){
			ret = min(ret, mid);
			en = mid - 1;
		}else{
			st = mid + 1;
		}
	}
	cout << ret;
	return 0;
}
