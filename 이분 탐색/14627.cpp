#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll s,c;
ll d[1000001];

bool chk(ll mid){
	ll cnt = 0;
	for(int i=0; i<s; i++){
		cnt += d[i] / mid;
	}
	return cnt >= c;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s >> c;
	ll st = 1, en = 0;
	ll mid;
	ll ret = 0;
	ll sum = 0;
	for(int i=0; i<s; i++){
		cin >> d[i];
		sum += d[i];
		en = max(en, d[i]);
	}
	while(st <= en){
		mid = (st + en) / 2;
		if(chk(mid)){
			ret = mid;
			st = mid + 1;
		}else{
			en = mid - 1;
		}
	}
	cout << sum - ret * c;
	return 0;
}
