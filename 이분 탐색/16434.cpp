#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
ll n,atk;
ll t,a,h;
ll cur, mx;
pair<ll, pair<ll,ll>> d[123460];

bool chk(ll mid){
	cur = mid;
	ll curAtk = atk;
	for(int i=1; i<=n; i++){
		if(d[i].first == 1){ //monster
			ll ma = d[i].second.first;
			ll mh = d[i].second.second;
			ll div = mh / curAtk + (mh % curAtk ? 1:0);
			ll cnt = div - 1;
			cur -= cnt * ma;
			if(cur <= 0) return false;
		}
		if(d[i].first == 2){ //potion
			curAtk += d[i].second.first;
			cur += d[i].second.second;
			if(cur > mid) cur = mid;
		}
	}
	return true;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//t == 1 -> monster 
	//t == 2 -> potion
	cin >> n >> atk;
	for(int i=1; i<=n; i++){
		cin >> t >> a >> h;
		d[i].first = t;
		d[i].second = {a,h};
	}
	ll st = 1, mx = 1e18;
	ll ret, mid;
	
	while(st <= mx){
		mid = (st + mx) / 2;
		if(chk(mid)){
			ret = mid;
			mx = mid - 1;
		}else st = mid + 1;
	}
	cout << ret;
	return 0;
}








