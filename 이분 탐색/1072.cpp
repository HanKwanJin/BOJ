#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
ll x,y,z;

bool chk(ll mid){
	ll xx = x + mid;
	ll yy = y + mid;
	if((yy * 100 / xx) > z){
		return true;
	}
	return false;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> x >> y;
	if(x == y){
		cout << -1;
		return 0;
	}
	z = y * 100 / x;
	ll st = 0, en = 1e9;
	ll mid,ret=0;
	while(st <= en){
		mid = (st + en) / 2;
		if(chk(mid)){
			ret = mid;
			en = mid - 1;
		}else st = mid + 1;
	}
	cout << (ret ? ret : -1);
	return 0;
}
